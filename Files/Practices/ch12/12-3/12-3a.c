#include <stdio.h>

void set_mode(int * m)
{
    if (*m == 0 || *m == 1)
        return;
    else if (*m < -1)
    {
        printf("Invalid mode specified. Mode 0 (metric) used.\n");
        *m = 0;
    }
    else if (*m > 1)
    {
        printf("Invalid mode specified. Mode 1 (US) used.\n");
        *m = 1;
    }
    return;
}

void get_info(double *d, double *f, int m)
{
    if (m)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", d);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", f);
    }
    else
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", d);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", f);
    }
}

void show_info(double d, double f, int m)
{
    double fuel_c;

    if (m)
    {
        fuel_c = d / f ;
        printf("Fuel consumption is %.1f miles per gallon.\n", fuel_c);
    }
    else
    {
        fuel_c = f / (d / 100.0);
        printf("Fuel consumption is %.2f liters per 100 km.\n", fuel_c);
    }
}
