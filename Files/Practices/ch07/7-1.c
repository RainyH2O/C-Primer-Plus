#include <stdio.h>

int main(void)
{
    char ch;
    int s_c = 0;
    int l_c = 0;
    int o_c = 0;

    printf("Enter: ");
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            s_c++;
        else if (ch == '\n')
            l_c++;
        else
            o_c++;
    }
    printf("Space: %d\nLine: %d\nOther: %d", s_c, l_c, o_c);
    return 0;
}
