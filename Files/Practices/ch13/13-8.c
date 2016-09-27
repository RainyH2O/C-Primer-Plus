#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int i;
    int ch;
    int count;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s character files\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc == 2)
    {
        count = 0;
        while ((ch = getchar()) != EOF)
            if (ch == argv[1][0])
                count++;
        printf("The number of %c in input: %d\n", argv[i], count);
    }
    else
        for (i = 2; i < argc; i++)
        {
            count = 0;
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "can't open file %s\n",argv[i]);
                continue;
            }
            while ((ch = getc(fp)) != EOF)
                if (ch == argv[1][0])
                    count++;
            printf("The number of %c in file %s: %d\n", argv[1][0], argv[i], count);
            if (fclose(fp) != 0)
                fprintf(stderr, "Can't close file %s\n", argv[i]);
        }

    return 0;
}
