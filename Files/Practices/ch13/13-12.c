#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS 30

char tochar(int);

int main(void)
{
    FILE *in, *out;
    char name[COLS];
    int data[ROWS][COLS];
    int i, j;
    int num;
    char gra[ROWS][COLS + 1];

    printf("Enter the name of data file: ");
    gets(name);
    if ((in = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", name);
        exit(EXIT_FAILURE);
    }
    if ((out = fopen("Output", "w")) == NULL)
    {
        fprintf(stderr, "Can't create file Output\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
        {
            while ((num = getc(in)) == '\n' || num == ' ' || num == '\t')
                continue;
            data[i][j] = num;
        }

    for (i = 0; i < ROWS; i++)
        for(j = 0; j < COLS + 1; j++)
        {
            if (j == COLS)
                gra[i][j] = '\0';
            else
                gra[i][j] = tochar(data[i][j]);
        }

    for (i = 0; i < ROWS; i++)
        puts(gra[i]);

    for (i = 0; i < ROWS; i++)
    {
        fputs(gra[i], out);
        putc('\n', out);
    }

    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}

char tochar(int num)
{
    char ch;

    switch (num)
    {
        case '0':
            ch = ' ';
            break;
        case '1':
            ch = '.';
            break;
        case '2':
            ch = '\'';
            break;
        case '3':
            ch = ':';
            break;
        case '4':
            ch = '~';
            break;
        case '5':
            ch = '*';
            break;
        case '6':
            ch = '=';
            break;
        case '7':
            ch = '\"';
            break;
        case '8':
            ch = '%';
            break;
        case '9':
            ch = '#';
            break;
    }

    return ch;
}
