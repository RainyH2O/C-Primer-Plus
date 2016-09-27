#include <stdio.h>
#define N 60
int main(void)
{
    int time,h_time,m_time;

    printf("Enter time in minutes:");
    scanf("%d", &time);
    while (time > 0)
    {
        h_time = time / 60;
        m_time = time % 60;
        printf("Hours:%d,Minutes:%d\n", h_time, m_time);
        printf("Enter the next times:");
        scanf("%d", &time);
    }
    printf("Done!\n");

    return 0;
}
