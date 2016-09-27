#include <stdio.h>

int main(void)
{
    char ch;
    int times = 0;

    printf("Enter some text: ");
    while ((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            ch = '!';
            putchar(ch);
            times++;
        }
        else if (ch == '!')
        {
            putchar(ch);
            putchar(ch);
            times++;
        }
        else
            putchar(ch);
    }
    printf("\nTimes: %d\n", times);
    printf("Done!\n");

    return 0;
}
