/* mall.c -- ʹ��Queue�ӿ� */
/* ��queue.cһ����� */
#include <stdio.h>
#include <stdlib.h>                 /* Ϊrand()��srand()�����ṩԭ��    */
#include <time.h>                   /* Ϊtime()�����ṩԭ��             */
#include "queue.h"                  /* �ı�Item��typedef                */
#define MIN_PER_HR 60.0

bool newcustomer(double x);         /* ���¹˿͵�����                 */
Item customertime(long when);       /* ���ù˿Ͳ���                     */

int main(void)
{
    Queue line1, line2;
    Item temp;                      /* �����¹˿͵�����                 */
    int hours;                      /* ģ���Сʱ��                     */
    int perhour;                    /* ÿСʱ�˿͵�ƽ����               */
    long cycle, cyclelimit;         /* ѭ�������������������Ͻ�         */
    long turnaways = 0;             /* ��������������ܾ��Ĺ˿���       */
    long customers = 0;             /* ��������еĹ˿���               */
    long served = 0;                /* ��ģ���ڼ�õ�����Ĺ˿���       */
    long sum_line = 0;              /* �ۼƵĶ��г���                   */
    int wait_time = 0;              /* �ӵ�ǰ��Sigmund���������ʱ��    */
    double min_per_cust;            /* �˿͵�����ƽ�����ʱ��           */
    long line_wait = 0;             /* �����ۼƵȴ�ʱ��                 */

    InitializeQueue(&line1);
    InitializeQueue(&line2);
    srand(time(0));                 /* �����ʼ��rand()�ĺ���           */
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line1) && QueueIsFull(&line2))
                turnaways++;
            else if(!QueueIsFull(&line1))
            {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line1);
            }
            else
            {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line2);
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line1))
        {
            DeQueue(&temp, &line1);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        else if (wait_time <= 0 && !QueueIsEmpty(&line2))
        {
            DeQueue(&temp, &line2);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += QueueItemCount(&line1) + QueueItemCount(&line2);
    }

    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("         turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n",
               (double) sum_line / cyclelimit);
        printf(" average wait time: %.2f minutes\n",
               (double) line_wait / served);
    }
    else
        puts("No customers!");
    EmptyTheQueue(&line1);
    EmptyTheQueue(&line2);
    puts("Bye!");

    return 0;
}

/* x�ǹ˿͵�����ƽ�����ʱ�䣨����ƣ�                                  */
/* �����һ�������й˿͵������򷵻�true                                 */
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

/* when�ǹ˿͵�����ʱ��                                                 */
/* ����������һ��Item�ṹ���ýṹ�Ĺ˿͵���ʱ������Ϊwhen               */
/* ��Ҫ����ѯʱ������Ϊһ����Χ��1��3֮������ֵ                       */
Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
