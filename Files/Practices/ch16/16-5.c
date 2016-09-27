#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM 10

void roll_n(int [], int, int);
int main(void)
{
    int t;
    int arr[LIM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Please enter the times of number: ");
    while (scanf("%d", &t) != 1 || t < 0 || t > LIM)
        printf("Enter wrong! Enter a number 0 to %d: ", LIM);
    roll_n(arr, LIM, t);

    return 0;
}

void roll_n(int a[], int n, int t)
{
    int i, j;
    int temp;

    srand((unsigned int) time(0));
    for (j = 0; j < t; j++, n--)
    {
        i = rand() % n;
        printf("%d ", a[i]);
        temp = a[i];
        a[i] = a[n - 1];
        a[n - 1] = temp;
    }
    putchar('\n');
    printf("Over!\n");

    return;
}
