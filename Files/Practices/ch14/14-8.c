#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LEN 10
#define LIM 12
#define NO 0
#define YES 1

struct name {
    char fname[LEN];
    char lname[LEN];
};

struct seat {
    int num;
    int assigned;
    struct name names;
};

char showmenu(void);
void eatline(void);
void showempty_num(const struct seat [], int);
void showempty_list(const struct seat [], int);
void showlist(struct seat *ptstr[], int n);
void assignseat(struct seat [], int);
void deleteseat(struct seat [], int);

int main(void)
{
    FILE *fp;
    struct seat plane[LIM];
    struct seat *ptstr[LIM];
    char choice;
    int i;

    if ((fp = fopen("List.txt", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", "List.txt");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < LIM; i++)
    {
        plane[i].num = i + 1;
        plane[i].assigned = NO;
        ptstr[i] = &plane[i];
    }

    rewind(fp);
    while (fscanf(fp, "%d", &i) == 1)
    {
        if (fscanf(fp, "%s %s", plane[i - 1].names.fname, plane[i - 1].names.lname) == 2)
            plane[i - 1].assigned = YES;
        if (feof(fp))
            break;
    }
    fclose(fp);

    while ((choice = showmenu()) != 'f')
    {
        switch (choice)
        {
            case 'a': showempty_num(plane, LIM); break;
            case 'b': showempty_list(plane, LIM); break;
            case 'c': showlist(ptstr, LIM); break;
            case 'd': assignseat(plane, LIM); break;
            case 'e': deleteseat(plane, LIM); break;
        }
        if ((fp = fopen("List.txt", "w")) == NULL)
        {
            fprintf(stderr, "Can't open file %s\n", "List.txt");
            exit(EXIT_FAILURE);
        }
        for (i = 0; i < LIM; i++)
        {
            if (plane[i].assigned == YES)
                fprintf(fp, "%d %s %s\n", plane[i].num, plane[i].names.fname, plane[i].names.lname);
        }
        fclose(fp);
    }
    printf("Bye!\n");

    return 0;
}

char showmenu(void)
{
    char ans;

    printf("To choose a function, enter its letter label:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit\n");

    ans = tolower(getchar());
    eatline();
    while (strchr("abcdef", ans) == NULL)
    {
        puts("Please enter a, b, c, d, e or f: ");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void showempty_num(const struct seat p[], int n)
{
    int i;
    int count;

    for (count = 0, i = 0; i < n; i++)
    {
        if (p[i].assigned == NO)
            count++;
    }
    printf("There are %d empty seats\n", count);

    return;
}

void showempty_list(const struct seat p[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (p[i].assigned == NO)
            printf("%d\n", p[i].num);

    return;
}

void showlist(struct seat *ptstr[], int n)
{
    int top, seek;
    struct seat *temp;
    int i;

    for (top = 0; top < n - 1; top++)
        for (seek = top + 1; seek < n; seek++)
        {
            if (strcmp(ptstr[top]->names.fname, ptstr[seek]->names.fname) > 0)
            {
                    temp = ptstr[top];
                    ptstr[top] = ptstr[seek];
                    ptstr[seek] = temp;
            }
        }

    for (i = 0; i < n; i++)
    {
        if (ptstr[i]->assigned == YES)
            printf("%3d %s %s\n", ptstr[i]->num, ptstr[i]->names.fname, ptstr[i]->names.lname);
    }

    return;
}

void assignseat(struct seat p[], int n)
{
    struct seat temp;

    printf("Choose a number of seat (1-12)(q to quit): ");
    if (scanf("%d", &temp.num) == 1)
    {
        eatline();
        while (temp.num < 1 || temp.num > n)
        {
            printf("Please choose a number between 1 and 12: ");
            scanf("%d", &temp.num);
            eatline();
        }
        while (p[temp.num - 1].assigned == YES)
        {
            printf("Please choose another empty seat: ");
            scanf("%d", &temp.num);
            eatline();
            while (temp.num < 1 || temp.num > n)
            {
                printf("Please choose a number between 1 and 12: ");
                scanf("%d", &temp.num);
                eatline();
            }
        }
        printf("Please enter your first name(q to quit): ");
        if (gets(temp.names.fname) != NULL && temp.names.fname[0] != 'q')
        {
            printf("Please enter your last name(q to quit): ");
            if (gets(temp.names.lname) != NULL && temp.names.lname[0] != 'q')
            {
                temp.assigned = YES;
                p[temp.num - 1] = temp;
            }
        }

        printf("Done!\n");
    }
    else
        eatline();

    return;
}

void deleteseat(struct seat p[], int n)
{
    int num;
    int i;

    printf("Choose a number of seat (1-12)(q to quit): ");
    if (scanf("%d", &num) == 1)
    {
        eatline();
        while (num < 1 || num > n)
        {
            printf("Please choose a number between 1 and 12: ");
            scanf("%d", &num);
            eatline();
        }
        while (p[num - 1].assigned == NO)
        {
            printf("Please choose another non-empty seat: ");
            scanf("%d", &num);
            eatline();
            while (num < 1 || num > n)
            {
                printf("Please choose a number between 1 and 12: ");
                scanf("%d", &num);
                eatline();
            }
        }
    }
    else
        eatline();

    for (i = 0; i < n; i++)
        if (p[i].num == num)
            p[i].assigned = NO;

    return;
}
