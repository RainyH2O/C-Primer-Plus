#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *sf, *tf;
    char byte;

    if (argc != 3)
    {
        printf("Usage: %s sourcefile targetname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((sf = fopen(argv[1], "rb")) == NULL)
    {
        printf("Can't open sourcefile\n");
        exit(EXIT_FAILURE);
    }

    if ((tf = fopen(argv[2], "wb")) == NULL)
    {
        printf("Can't open targetname\n");
        exit(EXIT_FAILURE);
    }

    while ((byte = getc(sf)) != EOF)
        putc(byte, tf);

    if (fclose(sf) != 0)
        printf("Can't close sourcefile.\n");
    if (fclose(tf) != 0)
        printf("Can't close targetfile.\n");

    return 0;
}
