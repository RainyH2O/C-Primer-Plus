#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void show_array(const double ar[], int n);
double * new_d_array(int n, ...);
int main()
{
    double * p1;
    double * p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);

    return 0;
}

void show_array(const double ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
        printf("%g ", ar[index]);
    putchar('\n');

    return;
}

double * new_d_array(int n, ...)
{
    va_list ap;
    double * ptd;
    int i;

    va_start(ap, n);
    ptd = (double *) malloc(n * sizeof (double));
    if (ptd == NULL)
    {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < n; i++)
        ptd[i] = va_arg(ap, double);
    va_end(ap);

    return ptd;
}
