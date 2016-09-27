#include <stdio.h>

void copy_arr(double [], double [], int);
void copy_ptr(double *, double *, int);

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    int i;

    copy_arr(source, target1, 5);
    copy_ptr(source, target2, 5);

    printf("Target1: ");
    for (i = 0; i < 5; i++)
        printf("%.1f ", target1[i]);
    putchar('\n');
    printf("Target2: ");
    for (i = 0; i < 5; i++)
        printf("%.1f ", target2[i]);
    putchar('\n');

    return 0;
}

void copy_arr(double s[], double t[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        t[i] = s[i];
}

void copy_ptr(double * s, double * t, int n)
{
    int i;

    for (i = 0; i < n; i++)
        *(t + i) = *(s + i);
}
