#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 5

struct names {
    char first[40];
    char last[40];
};

void showarray(const struct names ar[], int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
    struct names staff[NUM] = {{"Si", "Li"}, {"San", "Zhang"}, {"Wu", "Wang"}, {"Er", "Zhao"}, {"Liu", "Sun"}};
    puts("Random list:");
    showarray(staff, NUM);
    qsort(staff, NUM, sizeof(struct names), mycomp);
    puts("\nSorted list:");
    showarray(staff, NUM);
    return 0;
}

void showarray(const struct names ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
        printf("%s %s\n", ar[index].first, ar[index].last);

}

int mycomp(const void * p1, const void * p2)
{
    const struct names * ps1 = (const struct names *) p1;
    const struct names * ps2 = (const struct names *) p2;
    int res;

    res = strcmp(ps1->last, ps2->last);
    if (res != 0)
        return res;
    else
        return strcmp(ps1->first, ps2->first);
}
