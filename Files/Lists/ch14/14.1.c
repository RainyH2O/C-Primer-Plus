/* book.c -- ������һ�����ͼ��Ŀ¼ */
#include <stdio.h>
#define MAXTITL 41      /* ��������󳤶�+1 */
#define MAXAUTL 31      /* ����������󳤶�+1 */
struct book {           /* �ṹģ�壺���Ϊbook */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};                      /* �ṹģ����� */
int main(void)
{
    struct book library;    /* ��library����Ϊbook���͵ı��� */
    printf("Please enter the book title.\n");
    gets(library.title);     /* ����title���� */
    printf("Now enter the author.\n");
    gets(library.author);
    printf("Now enter the value.\n");
    scanf("%f", &library.value);
    printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
    printf("Done.\n");

    return 0;
}
