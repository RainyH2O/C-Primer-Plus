#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int n_words = 0;
    int n_uppch = 0;
    int n_lowch = 0;
    int n_punch = 0;
    int n_numch = 0;
    int inword = 0;

    printf("Input: ");
    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch) && !inword)
        {
            inword = 1;
            n_words++;
        }
        if (isspace(ch) && inword)
            inword = 0;
        if (isupper(ch))
            n_uppch++;
        else if (islower(ch))
            n_lowch++;
        else if (ispunct(ch))
            n_punch++;
        else if(isdigit(ch))
            n_numch++;
    }
    printf("Words: %d\n", n_words);
    printf("Upper characters: %d\n", n_uppch);
    printf("Lower characters: %d\n", n_lowch);
    printf("Punct: %d\n", n_punch);
    printf("Number: %d\n", n_numch);

    return 0;
}
