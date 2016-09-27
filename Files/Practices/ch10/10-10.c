#include <stdio.h>
#define ROWS 3
#define COLS 5

void show_arr(int (* ar)[COLS], int rows);
void double_arr(int (* ar)[COLS], int rows);

int main(void)
{
    int arr[3][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}};

    show_arr(arr, ROWS);
    double_arr(arr, ROWS);
    show_arr(arr, ROWS);

    return 0;
}

void show_arr(int (* ar)[COLS], int rows)
{
    int r;
    int c;

    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < COLS; c++)
            printf("%d ", ar[r][c]);
        putchar('\n');
    }
}

void double_arr(int (* ar)[COLS], int rows)
{
    int r;
    int c;

    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            ar[r][c] *= 2;
}
