/* addemup.c -- 4�����͵���� */
#include <stdio.h>
int main(void)              /* ���ǰ20�������ĺ� */
{
    int count, sum, i;      /* �������           */

    count = 0;              /* ��ֵ���           */
    sum = 0;                /* ͬ��               */
    printf("Enter the upper limit: ");
    scanf("%d", &i);
    while (count++ < i)     /* while              */
        sum = sum + count;  /* ���               */
    printf("sum = %d\n", sum);  /* �������       */
    return 0;
}
