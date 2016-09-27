#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1024

int main(int argc, char *argv[])
{
    FILE *fp;
    char buf[LEN];

    if (argc != 3)
    {
        printf("Usage: %s string file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    while (fgets(buf, LEN, fp) != NULL)
        if (strstr(buf, argv[1]) != NULL)
            fputs(buf, stdout);

    if (fclose(fp) != 0)
        fprintf(stderr,"Can't close file %s", argv[2]);

    return 0;
}
