/* count.c -- 使用标准I/O */
#include <stdio.h>

#include <stdlib.h> // ANSI C的exit()原型
int main(int argc, char *argv[])
{
    int ch;         // 读取时存储每个字符的位置
    FILE *fp;       // 文件指针
    long count = 0;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(1);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);   // 相当于putchar(ch);
        count++;
    }
    fclose(fp);
    printf("File %s has %ld characters\n", argv[1], count);
    return 0;
}
