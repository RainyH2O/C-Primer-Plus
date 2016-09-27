/* misuse.c -- 不正确地使用函数 */
#include <stdio.h>
int imax();     /* 旧式的函数声明 */
int main(void)
{
    printf("The maximun of %d and %d is %d.\n",
           3, 5, imax(3));
    printf("The maximun of %d and %d is %d.\n",
           3, 5, imax(3.0, 5.0));
    return 0;
}

int imax(n, m)
int n, m;
{
    int max;

    if (n > m)
        max = n;
    else
        max = m;

    return max;
}
