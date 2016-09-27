#include <stdio.h>

int main(void)
{
    double n;

    printf("Put in a float-pointing number:");
    scanf("%lf", &n);
    printf("a. The input is %0.1f or %0.1e\n", n, n);
    printf("b. The input is %+0.3f or %0.3E\n", n, n);

    return 0;
}
