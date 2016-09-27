#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int days(char []);

int main(void)
{
    char monname[10];
    int daytotal;

    printf("Enter the name of a month: ");
    while (gets(monname) != NULL && monname[0] != '\0')
    {
        daytotal = days(monname);

        if (daytotal > 0)
            printf("There are %d days though %s\n", daytotal, monname);
        else
            printf("%s is not valid input\n", monname);
        printf("Enter next name of a month: ");
    }

    return 0;
}

int days(char m[])
{
    int total = 0;
    int i;
    int monnum = 0;

    if (m[0] == '\0')
        total = -1;
    else
    {
        m[0] = toupper(m[0]);
        for (i = 1; m[i] != '\0'; i++)
            m[i] = tolower(m[i]);
        for (i = 0; i < 12; i++)
            if (strcmp(m, months[i].name) == 0)
            {
                monnum = months[i].monumb;
                break;
            }
        if (monnum == 0)
            total = -1;
        else
            for (i = 0; i < monnum; i++)
                total +=  months[i].days;
    }

    return total;
}
