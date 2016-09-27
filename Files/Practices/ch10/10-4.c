#include <stdio.h>
#define SIZE 10

int i_max(double *, int);

int main(void)
{
    double arr[SIZE] = {32.0, 54.6, 74.4, 33.4, 29.8, 82.3, 23.5, 52.9, 73.0, 69.2};

    printf("The index of maxmun in array is: %d\n", i_max(arr, SIZE));

    return 0;
}

int i_max(double * a, int n)
{
    int i, i_max;
    double m;

    for (i = 0, i_max = 0, m = a[0]; i < n; i++)
        if (m < a[i])
        {
            m = a[i];
            i_max = i;
        }

    return i_max;
}
