#include <stdio.h>

void show_arr2d(int, int, const double [*][*]);
void copy_arr2d(int, int, const double [*][*], double [*][*]);

int main(void)
{
    const double arr[3][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}};
    int rs = 3;
    int cs = 5;

    printf("Original array:\n");
    show_arr2d(rs, cs, arr);

    double tar[rs][cs];

    copy_arr2d(rs, cs, arr, tar);
    printf("Target array:\n");
    show_arr2d(rs, cs, tar);

    return 0;
}

void show_arr2d(int rows, int cols, const double arr[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%5.1f ", arr[i][j]);
        putchar('\n');
    }
}

void copy_arr2d(int rows, int cols, const double orig[rows][cols], double copy[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            copy[i][j] = orig[i][j];
}
