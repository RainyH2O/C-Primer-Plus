#include <stdio.h>

int main(void)
{
    double a[8], b[8];
    int i;

    printf("Enter 8 number: ");
    for (i = 0; i < 8; i++)
        scanf("%lf", &a[i]);
    b[0] = a[0];
    for (i = 0; i < 7; i++)
        b[i+1] = b[i] + a[i+1];
    for (i = 0; i < 8; i++)
        printf("%5.1f", a[i]);
    printf("\n");
    for (i = 0; i < 8; i++)
        printf("%5.1f", b[i]);
    printf("\n");

    return 0;
}
