/* booksave.c -- 把结构内容保存到文件中 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100                      /* 图书的最多本数  */
struct book {                           /* 建立book模板    */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char getlet(char []);
void getbook(struct book *);

int main(void)
{
    struct book library[MAXBKS];        /* 结构数组 */
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof (struct book);
    char ch;

    if ((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);;
        exit(1);
    }
    rewind(pbooks);                     /* 定位到文件开始处 */
    while (count < MAXBKS && fread(&library[count], size,
                1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title,
               library[count].author, library[count].value);
        printf("Do you want delete or modify this record? y/n\n");
        if (getlet("yn") == 'y')
        {
            printf("Delete or modify? d/m\n");
            ch = getlet("dm");
            switch (ch)
            {
                case 'd' :
                    break;
                case 'm' :
                    getbook(&library[count++]);
                    break;
            }
        }
        else
            count++;
    }
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && gets(library[count].title) != NULL
                          && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        gets(library[count].author);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;                   /* 清空输入行 */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    fclose(pbooks);
    if ((pbooks = fopen("book.dat", "w+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);;
        exit(1);
    }

    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
        rewind(pbooks);
        fwrite(library, size, count, pbooks);
    }
    else
        puts("No books? Too bad.\n");

    puts("Bye.\n");
    fclose(pbooks);

    return 0;
}

char getlet(char ar[])
{
    char ch;

    ch = getchar();
    while (strchr(ar, ch) == NULL)
    {
        while (getchar() != '\n')
            continue;
        printf("Please use the one of %s\n", ar);
        ch = getchar();
    }
    while (getchar() != '\n')
        continue;

    return ch;
}

void getbook(struct book *ptstr)
{
    char ch;
    struct book temp = *ptstr;

    printf("t. modify title     a. modify author\nv. modify value     s. save modify\nq. quit\n");
    while ((ch = getlet("tavsq")) != 'q')
    {
        switch (ch)
        {
            case 't' :
                puts("Please enter new book titles.");
                gets(temp.title);
                break;
            case 'a' :
                puts("Please enter new book author.");
                gets(temp.author);
                break;
            case 'v' :
                puts("Please enter new book value.");
                scanf("%f", &temp.value);
                while (getchar() != '\n')
                    continue;
                break;
            case 's' :
                *ptstr = temp;
                break;
        }
        printf("t. modify title     a. modify author\nv. modify value     s. save modify\nq. quit\n");
    }
}
