// when.c -- ��ʱ�˳�һ��ѭ��
#include <stdio.h>
int main(void)
{
    int n = 5;
    while (n < 7)                   // ��7��
    {
        printf("n = %d\n", n);
        n++;                        // ��10��
        printf("Now n = %d\n", n);  // ��11��
    }
    printf("The loop has finished.\n");
    return 0;
}
