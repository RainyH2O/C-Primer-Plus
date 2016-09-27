#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define ID_MASK 0xff
#define SIZE_MASK  0x7f00
#define LEFT       0
#define CENTER     0x8000
#define RIGHT      0x10000
#define ALIGN_MASK 0x18000
#define BOLD       0x20000
#define ITALIC     0x40000
#define UNDERLINE  0x80000

typedef unsigned long font;

void showfonts(font);
void showmenu(void);
char getlet(char *);
void eatline(void);
void chfontsid(font *);
void chfontsize(font *);
void chalignment(font *);

int main(void)
{
    font fonts = 1 | 12 << 8 | LEFT;
    char choice;

    showfonts(fonts);
    while ((choice = getlet("fsabiuq")) != 'q')
    {
        switch (choice)
        {
            case 'f': chfontsid(&fonts); break;
            case 's': chfontsize(&fonts); break;
            case 'a': chalignment(&fonts); break;
            case 'b': fonts ^= BOLD; break;
            case 'i': fonts ^= ITALIC; break;
            case 'u': fonts ^= UNDERLINE; break;
        }
        showfonts(fonts);
    }
    printf("Bye!\n");

    return 0;
}

void showfonts(font f)
{
    printf("ID SIZE ALIGNMENT  B   I   U\n");
    printf("%d  %d   ", f & ID_MASK, (f & SIZE_MASK) >> 8);
    switch(f & ALIGN_MASK)
    {
        case LEFT: printf("left      "); break;
        case CENTER: printf("center    "); break;
        case RIGHT: printf("right     "); break;
        default: printf("unknown   ");
    }
    printf("%s ", (f & BOLD) == BOLD? "on": "off");
    printf("%s ", (f & ITALIC) == ITALIC? "on": "off");
    printf("%s\n", (f & UNDERLINE) == UNDERLINE? "on": "off");

    showmenu();
}

void showmenu(void)
{
    printf("f) change fonts s) change size   a) change alignment\n");
    printf("b) toggle bold i) toggle italic u) toggle underline\n");
    printf("q) quit\n");
}

char getlet(char * s)
{
    char ch;

    ch = tolower(getchar());
    eatline();
    while (strchr(s, ch) == NULL)
    {
        printf("Please enter one of %s\n", s);
        ch = tolower(getchar());
        eatline();
    }

    return ch;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void chfontsid(font * pf)
{
    int id;

    printf("Enter fonts id (0-255): ");
    while (scanf("%d", &id) == 1)
    {
        eatline();
        if ((id & ID_MASK) != id)
        {
            printf("Please enter a number between 0 and 255: ");
            continue;
        }
        else
        {
            *pf &= ~ID_MASK;
            *pf |= id;
            break;
        }
    }
}

void chfontsize(font * pf)
{
    int size;

    printf("Enter fonts size (0-127): ");
    while (scanf("%d", &size) == 1)
    {
        eatline();
        if ((size & SIZE_MASK >> 8) != size)
        {
            printf("Please enter a number between 0 and 127: ");
            continue;
        }
        else
        {
            *pf &= ~SIZE_MASK;
            *pf |= size << 8;
            break;
        }
    }
}

void chalignment(font * pf)
{
    int choice;

    printf("Select alignment:\n");
    printf("l) left c) center r) right\n");
    if ((choice = getlet("lcrq")) != 'q')
    {
        *pf &= ~ALIGN_MASK;
        switch (choice)
        {
            case 'l': *pf |= LEFT; break;
            case 'c': *pf |= CENTER; break;
            case 'r': *pf |= RIGHT; break;
        }
    }
}
