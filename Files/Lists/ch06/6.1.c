/* summing.c -- ���û������������� */
#include <stdio.h>
int main(void)
{
    long num;
    long sum = 0L;  /* ��sum��ʼ��Ϊ�� */
    int status;

    printf("Please enter an integer to be summed. ");
    printf("(q to quit): ");
    status = scanf("%ld", &num);
    while (status == 1) /* ==����˼�ǡ����ڡ� */
    {
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        status = scanf("%ld", &num);
    }
    printf("Those integers sum to %ld.\n", sum);
    return 0;
}