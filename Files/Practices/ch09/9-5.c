#include <stdio.h>

void large_of(double *, double *);

int main(void)
{
    double n1, n2;

    printf("Please enter two numbers: ");
    while (scanf("%lf %lf", &n1, &n2) == 2)
    {
        printf("Number 1: %f\nNumber 2: %f\n", n1, n2);
        large_of(&n1, &n2);
        printf("Now:\nNumber 1: %f\nNumber 2: %f\n", n1, n2);
        printf("Please enter next two numbers: ");
    }
    printf("Bye!\n");

    return 0;
}

void large_of(double * x, double * y)
{
    double temp;

    temp = *x > *y ? *x: *y;
    *x = *y = temp;

    return;
}
