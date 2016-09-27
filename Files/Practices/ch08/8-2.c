#include <stdio.h>

int main(void)
{
    int ct = 0, col = 0;
    char ch, ch_show;

    printf("Entet some text: ");

    while ((ch = getchar()) != EOF)
    {
        if (col == 10)
        {
            col = 0;
            putchar('\n');
        }
        if (ch >= ' ')
            printf("%c %d ", ch, ch);
        else if (ch == '\n' )
        {
            printf("\\n %d\n", ch, ch);
            col = 0;
            continue;
        }
        else if (ch == '\t')
            printf("\\t %d ", ch, ch);
        else
        {
            ch_show = ch + 64;
            printf("^%c %d ", ch_show, ch);
        }
        col++;
    }

    return 0;
}
