#include <stdio.h>
#include <stdlib.h> // ANSI C的exit()原型

int main(void)
{
    int ch;         // 读取时存储每个字符的位置
    FILE *fp;       // 文件指针
    long count = 0;
    char name[30];

    printf("Enter filename: ");
    gets(name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s\n", name);
        exit(1);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);   // 相当于putchar(ch);
        count++;
    }
    fclose(fp);
    printf("File %s has %ld characters\n", name, count);

    return 0;
}
