#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 4

int showmenu(void);
void eatline(void);
void ToUpper(char []);
void ToLower(char []);
void Transpose(char []);
void Dummy(char []);
void show(void (*)(char []), char []);

int main(void)
{
    char line[81];
    char copy[81];
    int index;
    void (*arpf[LIM])(char [])= {ToUpper, ToLower, Transpose, Dummy};

    puts("Enter a string(empty line to quit):");
    while (gets(line) != NULL && line[0] != '\0')
    {
        while ((index = showmenu()) != 'n')
        {
            strcpy(copy, line);
            show(arpf[index], copy);
        }
    }
    puts("Bye!");

    return 0;
}

int showmenu(void)
{
    char ans;
    int i = 0;

    puts("Enter menu choice: ");
    puts("u) uppercase       l) lowercase");
    puts("t) transposed case o) original case");
    puts("n) next string");
    ans = tolower(getchar());
    eatline();
    while (strchr("ulton", ans) == NULL)
    {
        puts("Please enter a u, l, t, o, or n:");
        ans = tolower(getchar());
        eatline();
    }
    switch (ans)
    {
        case 'o':
            i++;
        case 't':
            i++;
        case 'l':
            i++;
        case 'u':
            break;
        case 'n':
            i = ans;
            break;
    }

    return i;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char * str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void Transpose(char * str)
{
    while (*str)
    {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}

void Dummy(char * str)
{

}

void show(void (* fp)(char []), char * str)
{
    (*fp)(str);
    puts(str);
}
