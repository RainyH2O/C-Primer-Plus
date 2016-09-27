/* list.c -- ֧���б�����ĺ���   */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* �ֲ�����ԭ��                   */
static void CopyToNode(Item item, Node * pnode);

/* �ӿں���                       */
/* ���б�����Ϊ���б�             */
void InitializeList(List * plist)
{
    * plist = NULL;
}

/* ����б�Ϊ���򷵻���           */
bool ListIsEmpty(const List * plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
}

/* ����б������򷵻���           */
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;

    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    return full;
}

/* ���ؽڵ���                     */
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = *plist;  /* ���õ��б�Ŀ�ʼ�� */

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;    /* ��1����Ϊ��һ���ڵ� */
    }
    return count;
}

/* ���������Ŀ�Ľڵ㣬��������ӵ� */
/* ��plistָ����б�������ʵ�ַ�����β�� */
bool AddItem(Item item, List * plist)
{
    Node * pnew;
    Node * scan = *plist;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;           /* ʧ��ʱ�˳�����      */

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL)           /* ���б���˰�pnew  */
        *plist = pnew;          /* �����б�ͷ��        */
    else
    {
        while (scan->next != NULL)
            scan = scan->next;  /* �ҵ��б��β        */
        scan->next = pnew;      /* ��pnew��ӵ���β��  */
    }
    return true;
}

/* ����ÿ���ڵ㲢�����Ƿֱ�ִ����pfunָ��ĺ��� */
void Traverse(const List * plist, void (* pfun)(Item item))
{
    Node * pnode = *plist;      /* ���õ��б�Ŀ�ʼ�� */
    while (pnode != NULL)
    {
        (*pfun)(pnode->item);   /* �Ѻ����������б��е���Ŀ     */
        pnode = pnode->next;    /* ǰ������һ�� */
    }
}

/* �ͷ���malloc()������ڴ� */
/* ���б�ָ������ΪNULL     */
void EmptyTheList(List * plist)
{
    Node * psave;
    while (*plist != NULL)
    {
        psave = (*plist)->next; /* ������һ���ڵ�ĵ�ַ   */
        free(*plist);           /* �ͷŵ�ǰ�ڵ�           */
        *plist = psave;         /* ǰ������һ���ڵ�       */
    }
}

/* �ֲ��������� */
/* ��һ����Ŀ���Ƶ�һ���ڵ��� */
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;         /* �ṹ����               */
}
