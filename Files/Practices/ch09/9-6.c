#include <stdio.h>

int chposition(char);

int main(void)
{
    char ch;
    int pos;

    printf("Please enter some text: ");
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            printf("Please enter next text: ");
            continue;
        }
        if ((pos = chposition(ch)) == EOF)
            printf("Character %c isn't alpha.\n", ch);
        else
        {
            printf("Character %c is alpha.\n", ch);
            printf("Character %c is %d in the alphabet.\n", ch, pos);
        }
    }
    printf("Bye!\n");

    return 0;
}

int chposition(char ch)
{
    int val;

    if (ch >= 'a' && ch <= 'z')
        val = ch - 'a' + 1;
    else if (ch >= 'A' && ch <= 'Z')
        val = ch - 'A' + 1;
    else
        val = EOF;

    return val;
}
