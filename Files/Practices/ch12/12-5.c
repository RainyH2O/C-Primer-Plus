#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int num[100];

    srand((unsigned int)time(0));

    for (int i = 0; i < 100; i++)
        num[i] = rand() % 10 + 1;

    for (int i = 0; i < 100; i++)
    printf("%d ", num[i]);
    printf("\n");

    int top;
    int seek;
    int temp;
    for (top = 0; top < 100 - 1; top++)
        for (seek = top + 1; seek < 100; seek++)
            if (num[top] < num[seek])
            {
                temp = num[top];
                num[top] = num[seek];
                num[seek] = temp;
            }

    for (int i = 0; i < 100; i++)
        printf("%d ", num[i]);

    return 0;
}
