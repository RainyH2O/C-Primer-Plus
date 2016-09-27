#include <stdio.h>
#include <stdlib.h>
#define LEN 30

int main(void)
{
    char name[LEN];
    FILE *fp;
    long pos;
    int ch;

    printf("Enter file name: ");
    gets(name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", name);
        exit(EXIT_FAILURE);
    }
    printf("Enter the position of begining: ");
    while (scanf("%d", &pos) == 1)
    {
        rewind(fp);
        while (fseek(fp, pos, SEEK_SET) != 0)
            printf("Overflow!\n");
        while ((ch = getc(fp)) != EOF && ch != '\n')
            putchar(ch);
        printf("\nEnter next position of begining: ");
    }
    if (fclose(fp) != 0)
        fprintf(stderr, "Can't close file %s\n", name);

    return 0;
}
