#include <stdio.h>
#define ROWS 2
#define COLS 10

void show_arr(double [][COLS], int);
void copy_arr(double [], double [], int);

int main(void)
{
    int i, j;
    double arr[ROWS][COLS] = {{1,3,5,7,9,11,13,15,17,19}, {21,23,25,27,29,31,33,35,37,39}};
    double tar[ROWS][COLS];

    printf("Original array:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
            printf("%5.1f ", arr[i][j]);
        putchar('\n');
    }

    for (i = 0; i < ROWS; i++)
        copy_arr(arr[i], tar[i], COLS);

    printf("Target array:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
            printf("%5.1f ", tar[i][j]);
        putchar('\n');
    }

    return 0;
}

void copy_arr(double s[], double t[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        t[i] = s[i];
}
