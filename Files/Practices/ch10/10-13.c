#include <stdio.h>
#define ROWS 3
#define COLS 5

void input_arr(int, int, double [*][*]);
double aver_arr_r(double [], int);
double aver_arr_a(int, int, double [*][*]);
double max_arr(int, int, double [*][*]);
void show_arr(int, int, double [*][*]);

int main(void)
{
    double arr[ROWS][COLS];
    int r;

    input_arr(ROWS, COLS, arr);
    printf("Array:\n");
    show_arr(ROWS, COLS, arr);
    for (r = 0; r < ROWS; r++)
        printf("The average of number set %d is: %f\n", r + 1, aver_arr_r(arr[r], COLS));
    printf("The average of all numbers is: %f\n", aver_arr_a(ROWS, COLS, arr));
    printf("The maximum number of these number is: %f\n", max_arr(ROWS, COLS, arr));

    return 0;
}

void input_arr(int r, int c, double a[r][c])
{
    int rows, cols;
    double num;

    printf("Please enter 5 float-pointng number for 3 number set:\n");
    for (rows = 0; rows < r; rows++)
        for (cols = 0; cols < c; cols++)
            scanf("%lf", &a[rows][cols]);
}

double aver_arr_r(double a[], int cols)
{
    int i;
    double total;

    for(total = 0, i = 0; i < cols; i++)
        total += a[i];

    return total / cols;
}

double aver_arr_a(int r, int c, double a[r][c])
{
    int rows, cols;
    double total;

    for (total = 0, rows = 0; rows < r; rows++)
        for (cols = 0; cols < c; cols++)
            total += a[rows][cols];

    return total / (rows * cols);
}

double max_arr(int r, int c, double a[r][c])
{
    double max;
    int rows, cols;

    for (max = a[0][0], rows = 0; rows < r; rows++)
        for(cols = 0; cols < c; cols++)
            max = max > a[rows][cols] ? max : a[rows][cols];

    return max;
}

void show_arr(int r, int c, double a[r][c])
{
    int rows, cols;

    for (rows = 0; rows < r; rows++)
    {
        for (cols = 0; cols < c; cols++)
            printf("%6.3f ",a[rows][cols]);
        putchar('\n');
    }
}
