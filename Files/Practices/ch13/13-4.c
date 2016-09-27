#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int i;
    int byte;

    if (argc == 1)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    for (i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            printf("Can't open %s file\n", argv[i]);
            continue;
        }

        while ((byte = getc(fp)) != EOF)
            putc(byte, stdout);

        if (fclose(fp) != 0)
            printf("Can't close %s file\n", argv[i]);;
    }

    return 0;
}
