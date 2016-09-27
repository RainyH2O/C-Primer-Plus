#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char ch;
    int c_ct = 0, w_ct = 0;
    bool inword = true;

    while ((ch = getchar()) != EOF)
    {
        if (ch != ' ' && ch != '\n')
            c_ct++;
        if (ch != ' ' && inword)
        {
            inword = false;
            w_ct++;
        }
        if (ch == ' ' && !inword)
            inword = true;
    }
    printf("Average: %d\n", c_ct / w_ct);

    return 0;
}
