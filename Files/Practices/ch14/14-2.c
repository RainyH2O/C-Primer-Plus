#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct month {
    char name[10];
    char abbrev[4];
    int days;
    int monumb;
};

const struct month months[12] =
{
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

int getday(int *, int *, int *);

int main(void)
{
    int year, mon, day;
    int i;
    int stat;
    int daytotal;

    while ((stat = getday(&year, &mon, &day)) != EOF)
    {
        if (stat == 1)
        {
            fprintf(stderr, "Input is invalid!\n");
            continue;
        }
        daytotal = 0;

        for (i = 0; i < mon - 1; i++)
            daytotal += months[i].days;
        daytotal += day;

        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            if (mon > 2)
                daytotal++;

        printf("There are %d days though %s %d, %d\n", daytotal, months[mon-1].abbrev, day, year);
    }
    printf("Bye!\n");

    return 0;
}

int getday(int *y, int *m, int *d)
{
    int flag = 0;
    int i;
    char monname[10];

    printf("Enter the number of a year: ");
        if (scanf("%d", y) != 1)
            flag = EOF;
        while(getchar() != '\n')
            continue;
    printf("Enter the number of a month: ");
        gets(monname);
    if (monname[0] == '\0')
        flag = EOF;
    else if (isdigit(monname[0]))
    {
        *m = atoi(monname);
        if (*m < 1 || *m > 12)
            flag = 1;
    }
    else if (isalpha(monname[0]))
    {
        monname[0] = toupper(monname[0]);
        for (i = 1; monname[i] != '\0'; i++)
            monname[i] = tolower(monname[i]);
        for (i = 1; i < 12; i++)
        {
            if (strlen(monname) == 3)
            {
                if (strcmp(monname, months[i].abbrev) == 0)
                {
                    *m = months[i].monumb;
                    flag = 0;
                    break;
                }
                else
                    flag = 1;
            }
            else
            {
                if (strcmp(monname, months[i].name) == 0)
                {
                    *m = months[i].monumb;
                    flag = 0;
                    break;
                }
                else
                    flag = 1;
            }
        }
    }
    printf("Enter the number of a day: ");
        if (scanf("%d", d) != 1)
            flag = EOF;
        while(getchar() != '\n')
            continue;
        if (*d < 1 || *d > 31)
            flag = 1;

    return flag;
}
