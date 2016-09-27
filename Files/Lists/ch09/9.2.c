/* lethead2.c */
#include <stdio.h>
#include <string.h>                             /* Ϊstrlen()�ṩԭ�� */
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

void show_n_char(char ch, int num);

int main(void)
{
    int spaces;

    show_n_char('*', WIDTH);                            /* ʹ�ó�����Ϊ����     */
    putchar('\n');
    show_n_char(SPACE, 12);                             /* ʹ�ó�����Ϊ����     */
    printf("%s\n", NAME);
    spaces = (WIDTH - strlen(ADDRESS)) / 2;
                                                        /* �ó������           */
                                                        /* ��Ҫ�������ٿո�     */
                                                        /* ��һ��������Ϊ����   */
    show_n_char(SPACE, spaces);
    printf("%s\n", ADDRESS);
    show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);
                                                        /* ��һ������ʽ��Ϊ���� */
    printf("%s\n", PLACE);
    show_n_char('*', WIDTH);
    putchar('\n');

    return 0;
}

/* show_ n_ char()���� */
void show_n_char(char ch, int num)
{
    int count;

    for (count = 1; count <= num; count++)
        putchar(ch);
}