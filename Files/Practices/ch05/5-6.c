/* addemup.c -- 4�����͵���� */
#include <stdio.h>
int main(void)              /* ���ǰ20�������ĺ� */
{
    int count, sum, i, n;   /* �������           */

    count = 0;              /* ��ֵ���           */
    sum = 0;                /* ͬ��               */
    printf("Enter the upper limit: ");
    scanf("%d", &i);
    while (count++ < i)     /* while              */
    {
        n = count * count;
        sum = sum + n;      /* ���               */
    }
    printf("sum = %d\n", sum);  /* �������       */
    return 0;
}
