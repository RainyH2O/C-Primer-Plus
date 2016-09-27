#include <stdio.h>

double min(double, double);

int main(void)
{
    double n1, n2;

    printf("Enter two number(q to quit):");
    while (scanf("%lf %lf", &n1, &n2) == 2)
    {
        printf("The maximum of %f and %f is: %f\n", n1, n2, min(n1, n2));
        printf("Enter next two number(q to quit):");
    }
    printf("Bye!\n");

    return 0;
}

double min(double x, double y)
{
    return x > y ? x: y;
}
