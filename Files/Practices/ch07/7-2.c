#include <stdio.h>

int main(void)
{
    char ch;
    int c_ct = 0;

    printf("Enter some text(# to quit): ");
    while ((ch = getchar()) != '#')
    {
        if (ch != '\n')
        {
            c_ct++;
            printf("Char: %c ASCII: %d ", ch, ch);
            if (c_ct % 8 == 0)
                printf("\n");
        }
        else
        {
            if (c_ct % 8 == 0)
                printf("\nEnter some text(# to quit): ");
            else
                printf("\n\nEnter some text(# to quit): ");
            c_ct = 0;
        }

    }
    printf("Done!\n");

    return 0;
}
