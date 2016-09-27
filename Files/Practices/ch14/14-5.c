#include <stdio.h>
#define CSIZE 4
#define SCORE 3

struct name {
    char fname[10];
    char lname[10];
};

struct student {
    struct name names;
    float grade[SCORE];
    float aver;
};

void getscore(struct student [], int);
void getaver(struct student [], int);
void putmesg(struct student [], int);
void putaver(struct student [], int);

int main(void)
{
    struct student class[CSIZE] = {
        {"Flip", "Snide"},
        {"Clare", "Voyans"},
        {"Bingo", "Higgs"},
        {"Fawn", "Hunter"}
    };

    getscore(class, CSIZE);
    getaver(class, CSIZE);
    putmesg(class, CSIZE);
    putaver(class, CSIZE);

    return 0;
}

void getscore(struct student ar[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("Enter %d score for %s %s: ", SCORE, ar[i].names.fname, ar[i].names.lname);
        for (j = 0; j < SCORE; j++)
            scanf("%f", &ar[i].grade[j]);
    }

    return;
}

void getaver(struct student ar[], int n)
{
    int i, j;
    float sum;

    for (i = 0; i < n; i++)
    {
        for (sum = 0, j = 0; j < SCORE; j++)
            sum += ar[i].grade[j];
        ar[i].aver = sum / SCORE;
    }

    return;
}

void putmesg(struct student ar[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("%s %s: ", ar[i].names.fname, ar[i].names.lname);
        for (j = 0; j < SCORE; j++)
            printf("%f ",ar[i].grade[j]);
        printf("Average = %f\n", ar[i].aver);
    }

    return;
}

void putaver(struct student ar[], int n)
{
    int i, j;
    float sum;

    for (j = 0; j < SCORE; j++)
    {
        for (sum = 0, i = 0; i < n; i++)
            sum += ar[i].grade[j];
        printf("Average of grade %d: %f\n", j, sum / n);
    }

    return;
}
