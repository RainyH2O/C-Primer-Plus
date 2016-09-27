/* tree.c -- 树类型的支持函数 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* 局部数据类型               */

typedef struct pair {
    Node * parent;
    Node * child;
} Pair;

/* 局部函数的原型             */
static Node * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode(Node * new_node, Node * root);
static void InOrder(const Node * root, void (* pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Node **ptr);
static void DeleteAllNodes(Node * ptr);

/* 函数定义                   */
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree * ptree)
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
    Node * new_node;
    Pair look;

    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;                       /* 提前返回 */
    }
    if ((look = SeekItem(pi, ptree)).child != NULL)
    {
        look.child->item.count++;
        return true;                        /* 提前返回 */
    }
    new_node = MakeNode(pi);                /* 指向新节点                */
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;                       /* 提前返回                  */
    }
    /* 成功创建了一个新节点 */
    ptree->size++;

    if (ptree->root == NULL)                /* 情况1：树为空树           */
        ptree->root = new_node;             /* 新节点即为树的根节点      */
    else                                    /* 情况2：树非空             */
        AddNode(new_node, ptree->root);     /* 把新节点添加到树中        */
    return true;                            /* 成功返回                  */
}

bool InTree(const Item * pi, const Tree * ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

const Item * WhereInTree(const Item * pi, const Tree * ptree)
{
    if (!InTree(pi, ptree))
        return NULL;
    else
        return &SeekItem(pi, ptree).child->item;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
    Pair look;
    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;

    if (look.child->item.count > 0)
        look.child->item.count--;
    else
    {
        if (look.parent == NULL)                /* 删除根项目                */
            DeleteNode(&ptree->root);
        else if (look.parent->left == look.child)
            DeleteNode(&look.parent->left);
        else
            DeleteNode(&look.parent->right);
        ptree->size--;
    }

    return true;
}

void Traverse(const Tree * ptree, void (* pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

/* 局部函数 */
static void InOrder(const Node * root, void (* pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Node * root)
{
    Node * pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode(Node * new_node, Node * root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)             /* 空子树                    */
            root->left = new_node;          /* 因此把节点添加到此处      */
        else
            AddNode(new_node, root->left);  /* 否则处理该子树            */
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else
    {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}

static bool ToLeft(const Item * i1, const Item * i2)
{
    if (strcmp(i1->word, i2->word) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
    if (strcmp(i1->word, i2->word) > 0)
        return true;
    else
        return false;
}

static Node * MakeNode(const Item * pi)
{
    Node * new_node;

    new_node = (Node *) malloc(sizeof(Node));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->item.count = 1;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair SeekItem(const Item * pi, const Tree * ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;                        /* 提前返回 */
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else        /* 如果前面两种情况都不满足，必定为相等的情况  */
            break;  /* look.child是目标项目节点的地址 */
    }
    return look;                            /* 成功返回 */
}

static void DeleteNode(Node **ptr)
/* ptr是指向目标节点的父节点指针成员的地址 */
{
    Node * temp;
    puts((*ptr)->item.word);
    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else        /* 被删除节点有两个子节点          */
    {
        /* 找到右子树的依附位置 */
        for (temp = (*ptr)->left; temp->right != NULL;
                temp = temp->right)
             continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}
