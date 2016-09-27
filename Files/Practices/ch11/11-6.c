#include <stdio.h>
#define SIZE 40

char *strncpy(char *, char *, int);

int main(void)
{
    char s1[SIZE];
    char s2[SIZE];
    int n;
    char *pt;

    printf("Enter a string: ");
    while (gets(s2) != NULL && s2[0] != '\0')
    {
        printf("Enter a limit number: ");
        scanf("%d", &n);
        while (getchar() != '\n')
            continue;
        pt = strncpy(s1, s2, n);
        printf("S1: ");
        puts(s1);
        puts(pt);
        printf("S2: ");
        puts(s2);

        printf("Enter next string: ");
    }
    puts("Done!");

    return 0;
}

char *strncpy(char *s1, char *s2, int n)
{
    int ct = 0;
    char * pt = s1;

    while (*s2 != '\0' && ct < n)
    {
        *pt++ = *s2++;
        ct++;
    }
        *pt = '\0';
    return s1;
}
