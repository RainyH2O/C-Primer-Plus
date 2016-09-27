/* tree.c -- �����͵�֧�ֺ��� */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "tree.h"

/* �ֲ���������               */

typedef struct pair {
    TreeNode * parent;
    TreeNode * child;
} Pair;

/* �ֲ�������ԭ��             */
static TreeNode * MakeTreeNode(const List * pi);
static bool ToLeft(const ListItem * i1, const TreeItem * i2);
static bool ToRight(const ListItem * i1, const TreeItem * i2);
static void AddTreeNode(TreeNode * new_node, TreeNode * root);
static void InOrder(const TreeNode * root, void (* pfun)(ListItem item));
static Pair SeekTreeItem(const ListItem * pi, const Tree * ptree);
static void DeleteTreeNode(TreeNode **ptr);
static void DeleteAllTreeNodes(TreeNode * ptr);
static int CountList(const TreeNode * root);

/* ��������                   */
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

int TreeListItemCount(const Tree * ptree)
{
    if (ptree != NULL)
        return CountList(ptree->root);
    else
        return 0;
}

bool AddTreeItem(ListItem pi, Tree * ptree)
{
    TreeNode * new_node;
    TreeNode * look;
    List new_list;

    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;                       /* ��ǰ���� */
    }
    if ((look = SeekTreeItem(&pi, ptree).child) != NULL)
    {
        AddListItem(pi, &look->treeitem.petinfo);
        look->treeitem.count++;
        return true;                        /* ��ǰ���� */
    }
    InitializeList(&new_list);
    AddListItem(pi, &new_list);
    new_node = MakeTreeNode(&new_list);         /* ָ���½ڵ�                */
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;                       /* ��ǰ����                  */
    }
    /* �ɹ�������һ���½ڵ� */
    ptree->size++;

    if (ptree->root == NULL)                /* ���1����Ϊ����           */
        ptree->root = new_node;             /* �½ڵ㼴Ϊ���ĸ��ڵ�      */
    else                                    /* ���2�����ǿ�             */
        AddTreeNode(new_node, ptree->root);     /* ���½ڵ���ӵ�����        */
    return true;                            /* �ɹ�����                  */
}

bool InTree(const TreeItem * pi, const Tree * ptree)
{
    return (SeekTreeItem(&pi->petinfo->listitem, ptree).child == NULL) ? false : true;
}

TreeNode * WhereInTree(const ListItem * pi, const Tree * ptree)
{
    TreeNode * look;

    look = SeekTreeItem(pi, ptree).child;

    return look;
}

bool DeleteTreeItem(const ListItem * pi, Tree * ptree)
{
    Pair look;
    look = SeekTreeItem(pi, ptree);
    if (look.child == NULL)
        return false;

    if (look.parent == NULL)                /* ɾ������Ŀ                */
        DeleteTreeNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteTreeNode(&look.parent->left);
    else
        DeleteTreeNode(&look.parent->right);
    ptree->size--;

    return true;
}

bool DeleteListItem(const ListItem * pi, Tree * ptree)
{
    Pair look;
    int i, n;

    look = SeekTreeItem(pi, ptree);

    if (look.child == NULL)
        return false;

    n = DeleteListNode(pi, &look.child->treeitem.petinfo);
    if (n == 0)
        return false;
    else
        for (i = 0; i < n; i++)
            look.child->treeitem.count--;

    if (look.child->treeitem.petinfo == NULL)
    {
        if (look.parent == NULL)                /* ɾ������Ŀ                */
            DeleteTreeNode(&ptree->root);
        else if (look.parent->left == look.child)
            DeleteTreeNode(&look.parent->left);
        else
            DeleteTreeNode(&look.parent->right);
    }
    if (TreeListItemCount(ptree) == 0)
        DeleteAll(ptree);

    return true;
}

void TraverseTree(const Tree * ptree, void (* pfun)(ListItem item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllTreeNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

/* �ֲ����� */
static void InOrder(const TreeNode * root, void (* pfun)(ListItem listitem))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        TraverseList(&root->treeitem.petinfo, pfun);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllTreeNodes(TreeNode * root)
{
    TreeNode * pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllTreeNodes(root->left);
        free(root);
        DeleteAllTreeNodes(pright);
    }
}

static void AddTreeNode(TreeNode * new_node, TreeNode * root)
{
    if (ToLeft(&new_node->treeitem.petinfo->listitem, &root->treeitem))
    {
        if (root->left == NULL)             /* ������                    */
            root->left = new_node;          /* ��˰ѽڵ���ӵ��˴�      */
        else
            AddTreeNode(new_node, root->left);  /* �����������            */
    }
    else if (ToRight(&new_node->treeitem.petinfo->listitem, &root->treeitem))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddTreeNode(new_node, root->right);
    }
    else                                    /* ��Ӧ������ͬ����Ŀ        */
    {
        fprintf(stderr, "location error in AddTreeNode()\n");
        exit(1);
    }
}

static bool ToLeft(const ListItem * i1, const TreeItem * i2)
{
    if (strcmp(i1->petname, i2->petinfo->listitem.petname) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const ListItem * i1, const TreeItem * i2)
{
    if (strcmp(i1->petname, i2->petinfo->listitem.petname) > 0)
        return true;
    else
        return false;
}

static TreeNode * MakeTreeNode(const List * pi)
{
    TreeNode * new_node;

    new_node = (TreeNode *) malloc(sizeof(TreeNode));
    if (new_node != NULL)
    {
        new_node->treeitem.petinfo = *pi;
        new_node->treeitem.count = 1;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair SeekTreeItem(const ListItem * pi, const Tree * ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;                        /* ��ǰ���� */
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->treeitem)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->treeitem)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else        /* ���ǰ����������������㣬�ض�Ϊ��ȵ����  */
            break;  /* look.child��Ŀ����Ŀ�ڵ�ĵ�ַ */
    }
    return look;                            /* �ɹ����� */
}

static void DeleteTreeNode(TreeNode **ptr)
/* ptr��ָ��Ŀ��ڵ�ĸ��ڵ�ָ���Ա�ĵ�ַ */
{
    TreeNode * temp;
    //puts((*ptr)->item.petname);
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
    else        /* ��ɾ���ڵ��������ӽڵ�          */
    {
        /* �ҵ�������������λ�� */
        for (temp = (*ptr)->left; temp->right != NULL;
                temp = temp->right)
             continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

static int CountList(const TreeNode * root)
{
    int num = 0;

    if (root != NULL)
    {
        num += CountList(root->left);
        num += root->treeitem.count;
        num += CountList(root->right);
    }

    return num;
}
