#include "nary_tree.h"

int initializeTree(nAryTree *t, size_t sizeInfo, void *rootInfo)
{
    t->sizeInfo = sizeInfo;
    t->root = create_child(sizeInfo, root_info);
    return SUCCESS;
}

/******************************************************
* Find a node with the same infomration as infoParent * 
* and adds a child to that node                       *
*******************************************************/
void addChild(nAryTree *t, void *infoParent, void *infoChild, int (*compare_info)(void *, void *))
{

}

Node *create_child(size_t t, void *info) 
{ 
    Node *n;
    n = (Node*) malloc(sizeof(Node));

    if (n == NULL) 
        return NULL;

    n->info = malloc(t);
    if (n->info == NULL) 
    {
        free(n);
        return NULL;
    }
    memcpy(n->info, info, t);

    n->myChildList->next = NULL;
    n->myChildList->child = NULL;

    return n;
}

ListNode *create_list_node()
{
    ListNode *ln = malloc (sizeof(ListNode));

    if(ln == NULL)
        return NULL;

    ln->next = NULL;
    ln->child = NULL;

    return ln;
}