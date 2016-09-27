#include <stdio.h>
#define SIZE 10

int max(int *,int);

int main(void)
{
    int arr[SIZE] = {12, 51, 72, 25, 23, 64, 21, 43, 32, 23};

    printf("The maximun number of the array is: %d\n", max(arr, SIZE));

    return 0;
}

int max(int * a, int n)
{
    int m, i;

    for (m = a[0], i = 0; i < n; i++)
        m = m > a[i] ? m : a[i];

    return m;
}
