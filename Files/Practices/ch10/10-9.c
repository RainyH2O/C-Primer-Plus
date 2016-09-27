#include <stdio.h>
#define SIZE 4

void add_arr(const int [], const int [], int [], int);
void show_arr(const int [], int);

int main(void)
{
    const int arr1[SIZE] = {2, 4, 5, 8};
    const int arr2[SIZE] = {1, 0, 4, 6};
    int arr3[SIZE];

    printf("Array1:\n");
    show_arr(arr1, SIZE);
    printf("Array2:\n");
    show_arr(arr2, SIZE);
    add_arr(arr1, arr2, arr3, SIZE);
    printf("Array3:\n");
    show_arr(arr3, SIZE);

    return 0;
}

void add_arr(const int a1[], const int a2[], int a3[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        a3[i] = a1[i] + a2[i];
}

void show_arr(const int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');
}
