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

void putmes(const struct mesage);

int main(void)
{
    int i;

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

    for (i = 0; i < 5; i++)
        putmes(mes[i]);

    return 0;
}

void putmes(const struct mesage m)
{
        if (m.names.mname[0] != '\0')
            printf("%s, %s %c. - %d\n", m.names.fname, m.names.lname, m.names.mname[0], m.num);
        else
            printf("%s, %s - %d\n", m.names.fname, m.names.lname, m.num);

    return;
}
