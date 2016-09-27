#include <stdio.h>
#include <math.h>
#define LEN 10

void transform(double [], double [], int, double (*pfun)(double));
void showarr(double [], int);
double twice(double);
double thrice(double);


int main(void)
{
    double source[LEN] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    double target[LEN];

    transform(source, target, LEN, sin);
    showarr(source, LEN);
    showarr(target, LEN);
    transform(source, target, LEN, sqrt);
    showarr(source, LEN);
    showarr(target, LEN);
    transform(source, target, LEN, twice);
    showarr(source, LEN);
    showarr(target, LEN);
    transform(source, target, LEN, thrice);
    showarr(source, LEN);
    showarr(target, LEN);

    return 0;
}

void transform(double s[],double t[], int n, double (*pfun)(double))
{
    int i;

    for (i = 0; i < n; i++)
        t[i] = (*pfun)(s[i]);

    return;
}

void showarr(double arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%f ", arr[i]);
    putchar('\n');

    return;
}

double twice(double num) {return num * 2;}
double thrice(double num) {return num * 3;}
