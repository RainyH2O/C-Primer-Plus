#include <stdio.h>

void Temperatures(double ft);

int main(void)
{
    double val;

    printf("Enter a Fahrenheit temperature: ");
    while (scanf("%lf", &val))
    {
        Temperatures(val);
        printf("Enter a Fahrenheit temperature: ");
    }
    printf("Bye!\n");

    return 0;
}

void Temperatures(double ft)
{
    const double C_F1 = 1.8;
    const double C_F2 = 32.0;
    const double K_C = 273.16;
    double ct, kt;

    ct = C_F1 * ft + C_F2;
    kt = ct + K_C;
    printf("Fahrenheit: %.2f\nCelsius: %.2f\nKelvin: %.2f\n", ft, ct, kt);
}
