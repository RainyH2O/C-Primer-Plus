#include <stdio.h>

struct name {
    char fname[10];
    char mname[10];
    char lname[10];
};

struct mesage {
    int num;
    struct name names;
};

void putmes(const struct mesage [], int);

int main(void)
{
    const struct mesage mes[5] = {
        {
            302039823,
            {"Dribble", "Merlin", "Flossie"}
        },
        {
            302039823,
            {"Dribble", "Merlin", "Flossie"}
        },
        {
            302039823,
            {"Dribble", "Merlin", "Flossie"}
        },
        {
            302039823,
            {"Dribble", "Merlin", "Flossie"}
        },
        {
            302039823,
            {"Dribble", "Merlin", "Flossie"}
        }
    };

    putmes(mes, 5);

    return 0;
}

void putmes(const struct mesage m[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (m[i].names.mname[0] != '\0')
            printf("%s, %s %c. - %d\n", m[i].names.fname, m[i].names.lname, m[i].names.mname[0], m[i].num);
        else
            printf("%s, %s - %d\n", m[i].names.fname, m[i].names.lname, m[i].num);

    return;
}
