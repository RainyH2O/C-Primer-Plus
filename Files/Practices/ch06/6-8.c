#include <stdio.h>

float cal(float m, float n);

int main(void)
{
    float a, b;

    printf("Enter two floating-point number: ");
    while (scanf("%f %f", &a, &b) == 2)
    {
        printf("(%f - %f) / (%f * %f) = %f\n", a, b, a, b, cal(a, b));
        printf("Enter next two number (q to quit): ");
    }

    return 0;
}

float cal(float m, float n)
{
    return (m - n) / (m * n);
}
