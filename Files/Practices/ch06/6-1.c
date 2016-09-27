#include <stdio.h>
#define SIZE 26

int main(void)
{
    char a[SIZE];
    int i, n;

    for (n = 'a', i = 0; n <= 'z';n++, i++)
        a[i] = n;

    for (i = 0; i < SIZE; i++)
        printf("%c\n", a[i]);

    return 0;
}
