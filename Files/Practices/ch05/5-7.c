#include <stdio.h>

void cube(float n);

int main(void)
{
    float n;

    printf("Enter a floating-point number: ");
    scanf("%f", &n);
    cube(n);

    return 0;
}

void cube(float n)
{
    printf("The cube of %f is: %f\n", n, n * n * n);
}
