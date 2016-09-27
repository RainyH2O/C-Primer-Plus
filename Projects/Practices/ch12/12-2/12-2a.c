// pe12-2a.c
#include <stdio.h>
#include "pe12-2a.h"

static int mode;
static double distance;
static double fuel;

void set_mode(int m)
{
    if (m > 1)
    {
        printf("Invalid mode specified. Mode 1 (US) used.\n");
        mode = 1;
    }
    else if (m < -1)
    {
        printf("Invalid mode specified. Mode 0 (metric) used.\n");
        mode = 0;
    }
    else
        mode = m;
}

void get_info(void)
{
    if (mode)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
    }
    else
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
    }
}

void show_info(void)
{
    double fuel_c;

    if (mode)
    {
        fuel_c = distance / fuel ;
        printf("Fuel consumption is %.1f miles per gallon.\n", fuel_c);
    }
    else
    {
        fuel_c = fuel / (distance / 100.0);
        printf("Fuel consumption is %.2f liters per 100 km.\n", fuel_c);
    }
}
