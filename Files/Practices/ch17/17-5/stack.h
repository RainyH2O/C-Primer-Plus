/* stack.h -- ջ���͵Ľӿ� */
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>
/* �����������Ŀ���� */
/* ���磺typedef int Item; */
typedef char Item;

#define MAXSTACK 100
typedef struct stack
{
    Item items[MAXSTACK];   /* �����Ϣ             */
    int top;                /* ��һ����λ������     */
} Stack;

/* ��������ʼ��ջ                                   */
/* ����ǰ��psָ��һ��ջ                             */
/* �����󣺸�ջ����ʼ��Ϊ��ջ                       */
void InitializeStack(Stack * ps);

/* ���������ջ�Ƿ�����                             */
/* ����ǰ��psָ��һ���ѳ�ʼ����ջ                   */
/* �����������ջ����������true�����򷵻�false    */
bool FullStack(const Stack * ps);

/* ���������ջ�Ƿ�Ϊ��                             */
/* ����ǰ��psָ��һ���ѳ�ʼ����ջ                   */
/* �����������ջΪ�գ�����true�����򷵻�false    */
bool EmptyStack(const Stack * ps);

/* ����������Ŀѹ��ջ��                             */
/* ����ǰ��psָ��һ���ѳ�ʼ����ջ                   */
/*         item��Ҫ�ŵ�ջ������Ŀ                   */
/* ���������ջ��Ϊ������item�ŵ�ջ��             */
/*         ��������true������                     */
/*         ���ı�ջ����������false                  */
bool Push(Item item, Stack * ps);

/* ��������ջ��ɾ����Ŀ                             */
/* ����ǰ��psָ��һ���ѳ�ʼ����ջ                   */
/* ���������ջ��Ϊ�գ�ջ������Ŀ                 */
/*         �����Ƶ�* pitem��������ջ��              */
/*         ɾ������������true�����                 */
/*         ��һ���������ջ��ջ������Ϊ��           */
/*         ���ջ��ʼʱ��Ϊ�գ�                     */
/*         ���ı�ջ����������false                  */
bool Pop(Item * pitem, Stack * ps);

#endif // _STACK_H_
