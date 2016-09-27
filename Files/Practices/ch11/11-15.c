#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char ch;

    if (argc != 2)
        printf("Usage: %s [-p | -u | -l]\n", argv[0]);
    else if(argv[1][0] != '-')
        printf("Usage: %s [-p | -u | -l]\n", argv[0]);
    else
    {
        printf("Enter a text: ");
        while ((ch = getchar()) != EOF)
        {
            switch (argv[1][1])
            {
                case 'p':
                    putchar(ch);
                    break;
                case 'u':
                    putchar(toupper(ch));
                    break;
                case 'l':
                    putchar(tolower(ch));
                    break;
                default:
                    printf("Usage: %s [-p | -u | -l]\n", argv[0]);
                    break;
            }
        }
    }

    return 0;
}
