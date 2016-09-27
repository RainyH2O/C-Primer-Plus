#include <stdio.h>

double harmonic(double, double);

int main(void)
{
    double n1, n2;

    printf("Enter a pair of numbers: ");
    while (scanf("%lf %lf", &n1, &n2) == 2)
    {
        printf("The harmonic average is: %f\n", harmonic(n1, n2));
        printf("Enter next pair of numbers: ");
    }
    printf("Bye!\n");

    return 0;
}

double harmonic(double num1, double num2)
{
    double har;

    har = 1 / ((1 / num1 + 1 / num2) / 2);

    return har;
}
