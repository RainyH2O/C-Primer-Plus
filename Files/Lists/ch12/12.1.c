/* hiding.c - ������ڵı��� */
#include <stdio.h>
int main()
{
    int x = 30;     /* ��ʼ�� */
    printf("x in outer block: %d\n", x);
    {
        int x = 77; /* �µ�x�����ǵ�һ��x */
        printf("x in inner block: %d\n", x);
    }
    printf("x in outer block: %d\n", x);
    while (x++ < 33)    /* ��ʼ��x */
    {
        int x = 100;    /* �µ�x�����ǵ�һ��x */
        x++;
        printf("x in while loop: %d\n", x);
    }
    printf("x in outer block: %d\n", x);
    return 0;
}
