#include <stdio.h>
#define LEN 10

void sortarr(int arr[], int n);
int searchnum(int arr[], int n, int num);

int main(void)
{
    int a[LEN] = {9, 3, 7, 23, 54, 12, 32, 15, 47, 62};
    int num;

    sortarr(a, LEN);
    printf("Enter a number: ");
    scanf("%d", &num);
    if (searchnum(a, LEN, num))
        printf("The num %d is found!\n", num);
    else
        printf("The num %d isn't found!\n", num);

    return 0;
}

void sortarr(int arr[], int n)
{
    int top, seek;
    int temp;

    for (top = 0; top < n - 1; top++)
        for (seek = top + 1; seek < n; seek++)
        {
            if (arr[top] > arr[seek])
            {
                temp = arr[seek];
                arr[seek] = arr[top];
                arr[top] = temp;
            }
        }

    return;
}

int searchnum(int arr[], int n, int num)
{
    int top = n - 1;
    int bottom = 0;
    int seek;

    seek = (top + bottom) / 2;
    while (bottom <= top)
    {
        if (arr[seek] > num)
            top = seek - 1;
        else if (arr[seek] < num)
            bottom = seek + 1;
        else
            break;
        seek = (top + bottom) / 2;
    }
    if (arr[seek] == num)
        return 1;
    else
        return 0;
}
