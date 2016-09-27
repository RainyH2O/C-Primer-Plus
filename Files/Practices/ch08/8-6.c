#include <stdio.h>

char get_first(void);

int main(void)
{
    char show;

    show = get_first();
    putchar(show);

    return 0;
}

char get_first(void)
{
    int ch;

    while ((ch = getchar()) == ' ' || ch == '\n' || ch == '\t')
        continue;
    while (getchar() != '\n')
        continue;
    return ch;
}
