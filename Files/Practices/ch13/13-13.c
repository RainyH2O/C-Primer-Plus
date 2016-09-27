#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS 30

char tochar(int);
void cutpul(int [][COLS], int);
int cmpabs(int, int);

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

    cutpul(data, ROWS);

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

    /*for (i = 0; i < ROWS; i++)
    {
        fputs(gra[i], out);
        putc('\n', out);
    }*/

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
            fprintf(out, "%c ", data[i][j]);
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

void cutpul(int data[][COLS], int rows)
{
    int r, c;

    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
        {
            if (r > 0 && r < COLS - 1 && c > 0 && c < COLS - 1)
            {
                if (cmpabs(data[r][c], data[r - 1][c]) > 1 && cmpabs(data[r][c], data[r + 1][c]) > 1 && cmpabs(data[r][c], data[r][c - 1]) > 1 && cmpabs(data[r][c], data[r][c + 1]) > 1)
                    data[r][c] = (data[r - 1][c] + data[r + 1][c] + data[r][c - 1] + data[r][c + 1]) / 4;
            }
            else if (r == 0 && c == 0)
            {
                if (cmpabs(data[r][c], data[r + 1][c]) > 1 && cmpabs(data[r][c], data[r][c + 1] > 1))
                    data[r][c] = (data[r + 1][c] + data[r][c + 1]) / 2;
            }
            else if (r == 0 && c == COLS - 1)
            {
                if (cmpabs(data[r][c], data[r + 1][c]) > 1 && cmpabs(data[r][c], data[r][c - 1] > 1))
                    data[r][c] = (data[r + 1][c] + data[r][c - 1]) / 2;
            }
            else if (r == rows - 1 && c == 0)
            {
                if (cmpabs(data[r][c], data[r - 1][c]) > 1 && cmpabs(data[r][c], data[r][c + 1]) > 1)
                    data[r][c] = (data[r - 1][c] + data[r][c + 1]) / 2;
            }
            else if (r == rows - 1 && c == COLS - 1)
            {
                if (cmpabs(data[r][c], data[r - 1][c]) > 1 && cmpabs(data[r][c], data[r][c - 1] > 1))
                    data[r][c] = (data[r - 1][c] + data[r][c - 1]) / 2;
            }
            else if (r == 0)
            {
                if (cmpabs(data[r][c], data[r + 1][c]) > 1 && cmpabs(data[r][c], data[r][c - 1]) > 1 && cmpabs(data[r][c], data[r][c + 1]) > 1)
                    data[r][c] = (data[r + 1][c] + data[r][c - 1] + data[r][c + 1]) / 3;
            }
            else if (r == rows - 1)
            {
                if (cmpabs(data[r][c], data[r - 1][c]) > 1 && cmpabs(data[r][c], data[r][c - 1]) > 1 && cmpabs(data[r][c], data[r][c + 1]) > 1)
                    data[r][c] = (data[r - 1][c] + data[r][c - 1] + data[r][c + 1]) / 3;
            }
            else if (c == 0)
            {
                if (cmpabs(data[r][c], data[r][c + 1]) > 1 && cmpabs(data[r][c], data[r - 1][c]) > 1 && cmpabs(data[r][c], data[r + 1][c]) > 1)
                    data[r][c] = (data[r][c + 1] + data[r - 1][c] + data[r + 1][c]) / 3;
            }
            else if (c == COLS - 1)
            {
                if (cmpabs(data[r][c], data[r][c - 1]) > 1 && cmpabs(data[r][c], data[r - 1][c]) > 1 && cmpabs(data[r][c], data[r + 1][c]) > 1)
                    data[r][c] = (data[r][c - 1] + data[r - 1][c] + data[r + 1][c]) / 3;
            }
        }
}

int cmpabs(int n1, int n2)
{
    return n1 - n2 > 0 ? n1 - n2 : n2 - n1;
}
