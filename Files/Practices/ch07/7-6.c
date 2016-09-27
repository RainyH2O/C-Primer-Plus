#include <stdio.h>

int main(void)
{
    char ch;
    char prev;
    int times = 0;

    printf("Enter some text: ");
    while ((ch = getchar()) != '#')
    {
        if (ch == 'e')
            prev = ch;
        if (ch == 'i' && prev == 'e')
            times++;
    }
    printf("The times of \"ei\" is %d.\n", times);

    return 0;
}
