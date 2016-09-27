/* addemup.c -- 4种类型的语句 */
#include <stdio.h>
int main(void)              /* 求出前20个整数的和 */
{
    int count, sum, i, n;   /* 声明语句           */

    count = 0;              /* 赋值语句           */
    sum = 0;                /* 同上               */
    printf("Enter the upper limit: ");
    scanf("%d", &i);
    while (count++ < i)     /* while              */
    {
        n = count * count;
        sum = sum + n;      /* 语句               */
    }
    printf("sum = %d\n", sum);  /* 函数语句       */
    return 0;
}
