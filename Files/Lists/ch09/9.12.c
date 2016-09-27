/* loccheck.c -- 查看变量的存储地址 */
#include <stdio.h>
void mikado(int);                   /* 声明函数     */
int main(void)
{
    int pooh = 2, bah = 5;          /* main()函数中的局部变量 */

    printf("In main(), pooh = %d and &pooh = %p\n",
           pooh, &pooh);
    printf("In main(), bah = %d and &bah = %p\n",
           bah, &bah);
    mikado(pooh);
    return 0;
}
void mikado(int bah)                /* 定义函数 */
{
    int pooh = 10;                  /* mikdo()函数中的局部变量 */

    printf("In mikado(), pooh = %d and &pooh = %p\n",
           pooh, &pooh);
    printf("In mikado(), bah = %d and &bah = %p\n",
           bah, &bah);
}
