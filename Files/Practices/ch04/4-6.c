#include <stdio.h>
#include <float.h>

int main(void)
{
    double n1 = 1.0 / 3.0;
    float n2 = 1.0 / 3.0;

    printf("%.4f %.12f %.16f\n", n1, n1, n1);
    printf("%.4f %.12f %.16f\n", n2, n2, n2);
    printf("%d %d\n", DBL_DIG, FLT_DIG);

    return 0;
}
