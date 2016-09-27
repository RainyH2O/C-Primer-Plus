#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char sname[30];
    char tname[30];
    FILE *sf, *tf;
    char byte;

    printf("Enter sourcefile name: ");
    gets(sname);
    if ((sf = fopen(sname, "rb")) == NULL)
    {
        printf("Can't open sourcefile\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter targetfile name: ");
    gets(tname);
    if ((tf = fopen(tname, "wb")) == NULL)
    {
        printf("Can't create targetfile\n");
        exit(EXIT_FAILURE);
    }

    while ((byte = getc(sf)) != EOF)
        putc(toupper(byte), tf);

    if (fclose(sf) != 0)
        printf("Can't close sourcefile\n");
    if (fclose(tf) != 0)
        printf("Can't close targetfile\n");

    return 0;
}
