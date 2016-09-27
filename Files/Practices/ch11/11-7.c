#include <stdio.h>
#define SIZE 30

const char *string_in(const char *,const char *);

int main(void)
{
    char s1[SIZE];
    char s2[SIZE];
    const char * pt;

    printf("Enter string 1: ");
    while (gets(s1) != NULL && s1[0] != '\0')
    {
        printf("Enter string 2: ");
        if (gets(s2) != NULL && s2[0] != '\0')
        {
            printf("String1: ");
            puts(s1);
            printf("String2: ");
            puts(s2);
            printf("pt = %p, s1 = %p\n", pt, s1);
            if (pt = string_in(s1, s2))
            {
                printf("pt = %p, s1 = %p\n", pt, s1);
                puts(pt);
                puts(s1);
            }

            else
                puts("String2 isn't in the String1!");
        }
        else
        {
            printf("Enter string 1: ");
            continue;
        }
        printf("Enter string 1: ");
    }
    puts("Done!");

    return 0;
}

const char *string_in(const char *s1,const char *s2)
{
    const char * pt;
    const char * temp = s2;

    while (*s1 != '\0')
    {
        if (*s1++ != *s2)
            continue;
        pt = --s1;
        while (*s2 != '\0')
        {
            if (*++s2 != *++s1)
                break;
        }
        if (*s2 != '\0')
        {
            s2 = temp;
            continue;
        }
        else
            return pt;
    }
    return NULL;
}
