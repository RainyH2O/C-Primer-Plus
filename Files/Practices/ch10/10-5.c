#include <stdio.h>
#define SIZE 10

double d_val(double [], int);

int main(void)
{
    double arr[SIZE] = {23.5, 32.5, 42.7, 37.5, 75.2, 12.0, 53.1, 27.2, 62.6, 54.0};

    printf("The maximun number minue minimum number of array is: %f\n", d_val(arr, SIZE));

    return 0;
}

double d_val(double a[], int n)
{
    double max;
    double min;
    int i;

    for (i = 0, max = min = a[0]; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
        if (min > a[i])
            min = a[i];
    }

    return max-min;
}
