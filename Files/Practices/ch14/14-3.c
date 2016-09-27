#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100      /* 最多可以容纳的图书册数  */
struct book {           /* 建立book模板            */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void strsrt_t(struct book *pts[], int n);
void strsrt_v(struct book *pts[], int n);

int main(void)
{
    struct book library[MAXBKS];    /* book结构数组 */
    struct book * ptstr[MAXBKS];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && gets(library[count].title) != NULL
                          && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        gets(library[count].author);
        printf("Now enter the value.\n");
        scanf("%f", &library[count].value);
        while (getchar() != '\n')
            continue;       /* 清空输入行 */
        ptstr[count] = &library[count++];
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
        strsrt_t(ptstr, count);
        printf("Here is the sorted list of your books by title:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", ptstr[index]->title,
                   ptstr[index]->author, ptstr[index]->value);
        strsrt_v(ptstr, count);
        printf("Here is the sorted list of your books by value:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", ptstr[index]->title,
                   ptstr[index]->author, ptstr[index]->value);
    }
    else
        printf("No books? Too bad.\n");
    return 0;
}

void strsrt_t(struct book *pts[], int n)
{
    int top, seek;
    struct book *temp;

    for (top = 0; top < n - 1; top++)
        for (seek = top + 1; seek < n; seek++)
        {
            if (strcmp(pts[top]->title, pts[seek]->title) > 0)
            {
                temp = pts[top];
                pts[top] = pts[seek];
                pts[seek] = temp;
            }
        }

    return;
}

void strsrt_v(struct book *pts[], int n)
{
    int top, seek;
    struct book *temp;

    for (top = 0; top < n - 1; top++)
        for (seek = top + 1; seek < n; seek++)
        {
            if (pts[top]->value > pts[seek]->value)
            {
                temp = pts[top];
                pts[top] = pts[seek];
                pts[seek] = temp;
            }
        }

    return;
}
