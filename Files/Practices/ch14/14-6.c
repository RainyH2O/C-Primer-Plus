#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 10
#define LIM 19

struct name {
    char fname[LEN];
    char lname[LEN];
};

struct player {
    int no;
    struct name names;
    int num_p;
    int num_h;
    int num_r;
    int num_rbi;
    float per_h;
};

int main(void)
{
    FILE *fp;
    char name[LEN];
    struct player team[LIM] = {0};
    int i, j;
    int ch;
    struct player temp;
    int flag = 1;

    printf("Enter file name: ");
    gets(name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s!\n", name);
        exit(EXIT_FAILURE);
    }

    rewind(fp);
    for (i = 0; i < LIM; i++)
    {
        while (fscanf(fp, "%d %s %s %d %d %d %d", &temp.no, &temp.names.fname, &temp.names.lname, &temp.num_p, &temp.num_h, &temp.num_r, &temp.num_rbi) == 7)
        {
            if (temp.no == i)
            {
                if (flag)
                {
                    team[i].no = temp.no;
                    for (j = 0; j < LEN; j++)
                    {
                        team[i].names.fname[j] = temp.names.fname[j];
                        team[i].names.lname[j] = temp.names.lname[j];
                    }
                    flag = 0;
                }
                team[i].num_p += temp.num_p;
                team[i].num_h += temp.num_h;
                team[i].num_r += temp.num_r;
                team[i].num_rbi += temp.num_rbi;
            }
            if (feof(fp))
            {
                rewind(fp);
                break;
            }
        }
        team[i].per_h = (float) team[i].num_h / (float) team[i].num_p;
        flag = 1;
    }

    for (i = 0; i < LIM; i++)
        printf("%d %s %s %d %d %d %d %f\n", team[i].no, team[i].names.fname, team[i].names.lname, team[i].num_p, team[i].num_h, team[i].num_r, team[i].num_rbi, team[i].per_h);

    if (fclose(fp) != 0)
        fprintf(stderr, "Can't close file %s\n", name);

    return 0;
}
