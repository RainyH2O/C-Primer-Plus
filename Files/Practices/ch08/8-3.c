#include <stdio.h>

int main(void)
{
    char ch;
    int u_ct = 0, l_ct = 0;

    while ((ch = getchar()) != EOF)
        if (ch >= 'A' && ch <= 'Z')
            u_ct++;
        else if (ch >= 'a' && ch <= 'z')
            l_ct++;
    printf("Uppercase characters: %d\n", u_ct);
    printf("Lowercase characters: %d\n", l_ct);

    return 0;
}
