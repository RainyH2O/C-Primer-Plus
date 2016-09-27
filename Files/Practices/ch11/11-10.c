#include <stdio.h>
#include <string.h>
#define LEN 81
#define LIM 10

void putorig(char **, int);
void putasc(char **, int);
void putlen(char **, int);
void putword(char **, int);
int wordlen(const char *);

int main(void)
{
    char str[LIM][LEN];
    char ch;
    char * ptstr[LIM];
    int ct = 0;
    int i;

    puts("Enter some string:");
    while (ct < LIM && gets(str[ct]) != NULL)
    {
        ptstr[ct] = str[ct];
        ct++;
    }
    puts("a. Print the list of strings");
    puts("b. Print the list of strings with the sequence of ASCII");
    puts("c. Print the list of strings with the sequence of length");
    puts("d. Print the list of strings with the lenth of first word");
    puts("q. quit");

    while ((ch = getchar()) != 'q')
    {
        while (getchar() != '\n')
            continue;
        switch (ch)
        {
            case 'a':
                putorig(ptstr, ct);
                break;
            case 'b':
                putasc(ptstr, ct);
                break;
            case 'c':
                putlen(ptstr, ct);
                break;
            case 'd':
                putword(ptstr, ct);
                break;
            default:
                puts("Wrong! Please enter a, b, c, d or q.\n");
                break;
        }
        for (i = 0; i < LIM; i++)
        ptstr[i] = str[i];
    }
    puts("Done!");

    return 0;
}

void putorig(char *string[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        puts(string[i]);
    putchar('\n');
}

void putasc(char *string[], int n)
{
    char * temp;
    int top, seek;

    for (top = 0; top < n - 1; top++)
    {
        for (seek = top + 1; seek < n; seek++)
            if (strcmp(string[top], string[seek]) > 0)
            {
                temp = string[top];
                string[top] = string[seek];
                string[seek] = temp;
            }
    }
    putorig(string, n);
}

void putlen(char *string[], int n)
{
    char * temp;
    int top, seek;

    for (top = 0; top < n - 1; top++)
    {
        for (seek = top + 1; seek < n; seek++)
            if (strlen(string[top]) > strlen(string[seek]))
            {
                temp = string[top];
                string[top] = string[seek];
                string[seek] = temp;
            }
    }
    putorig(string, n);
}

void putword(char *string[], int n)
{
    char * temp;
    int top, seek;

    for (top = 0; top < n - 1; top++)
    {
        for (seek = top + 1; seek < n; seek++)
            if (wordlen(string[top]) > wordlen(string[seek]))
            {
                temp = string[top];
                string[top] = string[seek];
                string[seek] = temp;
            }
    }
    putorig(string, n);
}

int wordlen(const char *string)
{
    int ct = 0;

    while (string[ct] != ' ' && string[ct] != '\n' && string[ct] != '\t' && string[ct] != '\0')
        ct++;

    return ct;
}
