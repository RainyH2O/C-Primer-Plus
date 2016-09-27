/* list.c -- 支持列表操作的函数   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* 局部函数原型                   */
static void CopyToListNode(ListItem item, ListNode * pnode);

/* 接口函数                       */
/* 把列表设置为空列表             */
void InitializeList(List * plist)
{
    * plist = NULL;
}

/* 如果列表为空则返回真           */
bool ListIsEmpty(const List * plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
}

/* 如果列表已满则返回真           */
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

/* 返回节点数                     */
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    ListNode * pnode = *plist;  /* 设置到列表的开始处 */

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;    /* 把1设置为下一个节点 */
    }
    return count;
}

/* 创建存放项目的节点，并把它添加到 */
/* 由plist指向的列表（较慢的实现方法）尾部 */
bool AddListItem(ListItem item, List * plist)
{
    ListNode * pnew;
    ListNode * scan = *plist;

    pnew = (ListNode *) malloc(sizeof(ListNode));
    if (pnew == NULL)
        return false;           /* 失败时退出函数      */

    CopyToListNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL)           /* 空列表，因此把pnew  */
        *plist = pnew;          /* 放在列表头部        */
    else
    {
        while (scan->next != NULL)
            scan = scan->next;  /* 找到列表结尾        */
        scan->next = pnew;      /* 把pnew添加到结尾处  */
    }
    return true;
}

/* 访问每个节点并对它们分别执行由pfun指向的函数 */
void TraverseList(const List * plist, void (* pfun)(ListItem item))
{
    ListNode * pnode = *plist;      /* 设置到列表的开始处 */
    while (pnode != NULL)
    {
        (*pfun)(pnode->listitem);   /* 把函数作用于列表中的项目     */
        pnode = pnode->next;    /* 前进到下一项 */
    }
}

/* 释放由malloc()分配的内存 */
/* 把列表指针设置为NULL     */
void EmptyTheList(List * plist)
{
    ListNode * psave;
    while (*plist != NULL)
    {
        psave = (*plist)->next; /* 保存下一个节点的地址   */
        free(*plist);           /* 释放当前节点           */
        *plist = psave;         /* 前进到下一个节点       */
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

/* 局部函数定义 */
/* 把一个项目复制到一个节点中 */
static void CopyToListNode(ListItem item, ListNode * pnode)
{
    pnode->listitem = item;         /* 结构复制               */
}
