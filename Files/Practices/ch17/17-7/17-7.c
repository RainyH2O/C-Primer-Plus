#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#define LEN 10

char menu(void);
void showall(const Tree * pt);
void showchoice(const Tree * pt);
void printitem(Item item);

int main(void)
{
    Tree wordcount;
    FILE * fp;
    char filename[LEN];
    char word[LEN];
    Item entry;
    char choice;

    printf("Please enter a file name: ");
    gets(filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s!\n", filename);
        exit(EXIT_FAILURE);
    }
    InitializeTree(&wordcount);

    while (fscanf(fp, "%s", word) == 1 && !TreeIsFull(&wordcount))
    {
        strcpy(entry.word, word);
        AddItem(&entry, &wordcount);
    }

    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 'a':
                showall(&wordcount);
                break;
            case 'b':
                showchoice(&wordcount);
                break;
            default:
                printf("Switch error!\n");
                break;
        }
    }
    fclose(fp);
    puts("Done!");

    return 0;
}

char menu(void)
{
    char ch;

    printf("Please enter a choice:\n");
    printf("a) show words list\n");
    printf("b) find a word\n");
    printf("q) quit\n");

    while((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);
        if (strchr("abq", ch) == NULL)
            printf("Please enter a b or q:\n");
        else
            break;
    }
    if (ch == EOF)
        ch = 'q';

    return ch;
}

void showall(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);

    return;
}

void showchoice(const Tree * pt)
{
    char word[LEN];
    Item seek;

    if (TreeIsEmpty(pt))
    {
       puts("No entries!");
       return;
    }

    printf("Please enter a word: ");
    scanf("%s", word);
    while (getchar() != '\n')
        continue;
    strcpy(seek.word, word);
    if (InTree(&seek, pt))
        printitem(*WhereInTree(&seek, pt));
    else
        printf("Not found the word %s!\n", word);

    return;
}

void printitem(Item item)
{
    printf("%-11s%-3d\n", item.word, item.count);

    return;
}
