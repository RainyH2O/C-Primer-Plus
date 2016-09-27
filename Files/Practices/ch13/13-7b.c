#include <stdio.h>
#include <stdlib.h>
#define LEN 30

void putline(FILE *, FILE *);

int main(void)
{
    char file1[LEN];
    char file2[LEN];
    FILE *fp1;
    FILE *fp2;

    printf("File1: ");
    gets(file1);

    if ((fp1 = fopen(file1, "r")) == NULL)
    {
        printf("Can't open file %s\n", file1);
        exit(EXIT_FAILURE);
    }

    printf("File2: ");
    gets(file2);

    if ((fp2 = fopen(file2, "r")) == NULL)
    {
        printf("Can't open file %s\n", file2);
        exit(EXIT_FAILURE);
    }
    putline(fp1, fp2);

    if (fclose(fp1) != 0)
        fprintf(stderr, "Can't close file %s\n", file1);
    if (fclose(fp2) != 0)
        fprintf(stderr, "can't close file %s\n", file2);

    return 0;
}

void putline(FILE *f1, FILE *f2)
{
    char ch1;
    char ch2;

    ch1 = getc(f1);
    ch2 = getc(f2);

    while (ch1 != EOF || ch2 != EOF)
    {
        while (ch1 != EOF && ch1 != '\n')
        {
            putchar(ch1);
            ch1 = getc(f1);
        }

        while (ch2 != EOF && ch2 != '\n')
        {
            putchar(ch2);
            ch2 = getc(f2);
        }

        if (ch1 == '\n' || ch2 == '\n')
        {
            putchar(ch2);
            ch1 = getc(f1);
            ch2 = getc(f2);
        }
    }

    return;
}
