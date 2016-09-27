#include <stdio.h>

int main(void)
{
    int x = 2147483647;
    float y =2e38, z = 2e-37;

    printf("%d\n", x+1);
    printf("%f\n",y+1);
    printf("%f\n",z-1);

    return 0;
}
