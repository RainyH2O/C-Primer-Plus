/* films2.c -- ʹ�ýṹ���� */
#include <stdio.h>
#include <stdlib.h>         /* �ṩmalloc()ԭ��   */
#include <string.h>         /* �ṩstrcpy()ԭ��   */
#define TSIZE 45            /* ���Ƭ���������С */
struct film {
    char title[TSIZE];
    int rating;
    struct film * prev;
    struct film * next;     /* ָ���������һ���ṹ */
};

int main(void)
{
    struct film * head = NULL;
    struct film * prev = NULL;
    struct film * current;
    char input[TSIZE];

    /* �ռ����洢��Ϣ */
    puts("Enter first movie title:");
    while (gets(input) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL)   /* ��һ���ṹ */
            head = current;
        else                /* �����ṹ   */
            prev->next = current;
        current->next = NULL;
        current->prev = prev;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

    /* ������Ӱ�б� */
    if (head == NULL)
        printf("No data entered. ");
    else
    {
        printf("Here is the movie list by ascend:\n");
        current = head;
        while (current != NULL)
        {
            printf("Movie: %s  Rating: %d\n", current->title, current->rating);
            prev = current;
            current = current->next;
        }
        printf("Here is the movie list by descend:\n");
        while (current != NULL)
            continue;
        current = prev;
        while (current != NULL)
        {
            printf("Movie: %s  Rating: %d\n", current->title, current->rating);
            current = current->prev;
        }
    }

    /* ��������ɣ�����ͷ���������ڴ� */
    current = head;
    while (current != NULL)
    {
        free(current);
        current = current->next;
    }
    printf("Bye!\n");

    return 0;
}
