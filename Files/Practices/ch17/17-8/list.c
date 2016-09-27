/* list.c -- ֧���б�����ĺ���   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* �ֲ�����ԭ��                   */
static void CopyToListNode(ListItem item, ListNode * pnode);

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
    ListNode * pt;
    bool full;

    pt = (ListNode *) malloc(sizeof(ListNode));
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
    ListNode * pnode = *plist;  /* ���õ��б�Ŀ�ʼ�� */

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;    /* ��1����Ϊ��һ���ڵ� */
    }
    return count;
}

/* ���������Ŀ�Ľڵ㣬��������ӵ� */
/* ��plistָ����б�������ʵ�ַ�����β�� */
bool AddListItem(ListItem item, List * plist)
{
    ListNode * pnew;
    ListNode * scan = *plist;

    pnew = (ListNode *) malloc(sizeof(ListNode));
    if (pnew == NULL)
        return false;           /* ʧ��ʱ�˳�����      */

    CopyToListNode(item, pnew);
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
void TraverseList(const List * plist, void (* pfun)(ListItem item))
{
    ListNode * pnode = *plist;      /* ���õ��б�Ŀ�ʼ�� */
    while (pnode != NULL)
    {
        (*pfun)(pnode->listitem);   /* �Ѻ����������б��е���Ŀ     */
        pnode = pnode->next;    /* ǰ������һ�� */
    }
}

/* �ͷ���malloc()������ڴ� */
/* ���б�ָ������ΪNULL     */
void EmptyTheList(List * plist)
{
    ListNode * psave;
    while (*plist != NULL)
    {
        psave = (*plist)->next; /* ������һ���ڵ�ĵ�ַ   */
        free(*plist);           /* �ͷŵ�ǰ�ڵ�           */
        *plist = psave;         /* ǰ������һ���ڵ�       */
    }
}

int DeleteListNode(const ListItem * pi, List * plist)
{
    ListNode * pnode;
    ListNode * psave;
    int ct = 0;

    pnode = *plist;
    psave = *plist;
    while (pnode != NULL)
    {
        if (strcmp(pnode->listitem.petkind, pi->petkind) == 0)
        {
            if (pnode == *plist)
                *plist = pnode->next;
            else
                psave->next = pnode->next;
            psave = pnode;
            pnode = pnode->next;
            free(psave);
            psave = pnode;
            ct++;
        }
        else
        {
            psave = pnode;
            pnode = pnode->next;
        }
    }

    return ct;
}

/* �ֲ��������� */
/* ��һ����Ŀ���Ƶ�һ���ڵ��� */
static void CopyToListNode(ListItem item, ListNode * pnode)
{
    pnode->listitem = item;         /* �ṹ����               */
}
