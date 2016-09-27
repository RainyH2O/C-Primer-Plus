#include <stdio.h>

void copy_arr(const double [], double [], int);

int main(void)
{
    const double arr[7] = {1,2,3,4,5,6,7};
    double tar[3];
    int i;

    printf("Original array:\n");
    for (i = 0; i < 7; i++)
        printf("%.1f ", arr[i]);
    putchar('\n');

    copy_arr(arr + 2, tar, 3);

    printf("Target array:\n");
    for (i = 0; i < 3; i++)
        printf("%.1f ", tar[i]);
    putchar('\n');

    return 0;
}

void copy_arr(const double s[], double t[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        t[i] = s[i];
}
