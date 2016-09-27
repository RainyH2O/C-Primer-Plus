/* hiding.c - 代码块内的变量 */
#include <stdio.h>
int main()
{
    int x = 30;     /* 初始化 */
    printf("x in outer block: %d\n", x);
    {
        int x = 77; /* 新的x，覆盖第一个x */
        printf("x in inner block: %d\n", x);
    }
    printf("x in outer block: %d\n", x);
    while (x++ < 33)    /* 初始化x */
    {
        int x = 100;    /* 新的x，覆盖第一个x */
        x++;
        printf("x in while loop: %d\n", x);
    }
    printf("x in outer block: %d\n", x);
    return 0;
}
