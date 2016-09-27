#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LEFT 0
#define CENTER 1
#define RIGHT 2
#define OFF 0
#define ON 1
#define ID_MASK 255
#define SIZE_MASK 127

struct font {
    unsigned int fontid:    8;
    unsigned int fontsize:  7;
    unsigned int alignment: 2;
    unsigned int bold:      1;
    unsigned int italic:    1;
    unsigned int underline: 1;
};

void showfont(struct font);
void showmenu(void);
char getlet(char *);
void eatline(void);
void chfontid(struct font *);
void chfontsize(struct font *);
void chalignment(struct font *);

int main(void)
{
    struct font fonts = {1, 12, LEFT, OFF, OFF, OFF};
    char choice;

    showfont(fonts);
    while ((choice = getlet("fsabiuq")) != 'q')
    {
        switch (choice)
        {
            case 'f': chfontid(&fonts); break;
            case 's': chfontsize(&fonts); break;
            case 'a': chalignment(&fonts); break;
            case 'b': fonts.bold = ~fonts.bold; break;
            case 'i': fonts.italic = ~fonts.italic; break;
            case 'u': fonts.underline = ~fonts.underline; break;
        }
        showfont(fonts);
    }
    printf("Bye!\n");

    return 0;
}

void showfont(struct font f)
{
    printf("ID SIZE ALIGNMENT  B   I   U\n");
    printf("%d  %d   ", f.fontid, f.fontsize);
    switch(f.alignment)
    {
        case LEFT: printf("left      "); break;
        case CENTER: printf("center    "); break;
        case RIGHT: printf("right     "); break;
        default: printf("unknown   ");
    }
    printf("%s ", f.bold? "on": "off");
    printf("%s ", f.italic? "on": "off");
    printf("%s\n", f.underline? "on": "off");

    showmenu();
}

void showmenu(void)
{
    printf("f) change font s) change size   a) change alignment\n");
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

void chfontid(struct font * ps)
{
    int id;

    printf("Enter font id (0-255): ");
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
            ps->fontid = id;
            break;
        }
    }
}

void chfontsize(struct font * ps)
{
    int size;

    printf("Enter font size (0-127): ");
    while (scanf("%d", &size) == 1)
    {
        eatline();
        if ((size & SIZE_MASK) != size)
        {
            printf("Please enter a number between 0 and 127: ");
            continue;
        }
        else
        {
            ps->fontsize = size;
            break;
        }
    }
}

void chalignment(struct font * ps)
{
    int choice;

    printf("Select alignment:\n");
    printf("l) left c) center r) right\n");
    if ((choice = getlet("lcrq")) != 'q')
    {
        switch (choice)
        {
            case 'l': ps->alignment = LEFT;
            case 'c': ps->alignment = CENTER;
            case 'r': ps->alignment = RIGHT;
        }
    }
}
