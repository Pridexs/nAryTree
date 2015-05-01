#include "nary_tree.h"

int initializeTree(nAryTree *t, size_t sizeInfo, void *rootInfo)
{
    t->sizeInfo = sizeInfo;
    t->root = create_child(sizeInfo, root_info);
    return SUCCESS;
}

/*******************************************************
* Finds a node with the same infomration as infoParent * 
* and adds a child to that node                        *
********************************************************/
void add_child(nAryTree *t, void *infoParent, void *infoChild, int (*compare_info)(void *, void *))
{
    ListNode *n;

    n = find_node(t->root, infoParent, compare_info);

    if(n == NULL)
        return ERROR_PARENT_NOT_FOUND;

    ListNode *ln = n->myChildList;

    // If the node doesnt have any child
    if (ln == NULL)
    {
        n->myChildList = create_list_node();
        if (n->myChildList == NULL)
            return ERROR;

        n->myChildList->child = create_child(t->sizeInfo, infoChild);
        if (n->myChildList->child == NULL)
            return ERROR;
    }
    // Else, we need to find the position where to insert
    else
    {
        while (ln->next != NULL)
        {
            ln = ln->next;
        }

        ln->next = create_list_node();
        if (ln->next == NULL)
            return ERROR;

        ln->next->child = create_child(t->sizeInfo, infoChild);
        if(ln->next->child == NULL)
            return ERROR;
    }

    return SUCCES;
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

    n->myChildList = NULL;

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

/********************************************
* Returns the pointer to the node with info *
* starting from the node n                  *
* PREORDER-Search                           *
*********************************************/
Node *find_node(Node *n, void *info, int (*compare_info)(void *, void *))
{
    // do we need to add error check if n = null ?
    
    // If the node has what we want, return its pointer
    if (compare_info(n->info, info) == 1) 
    {
        return n;
    }

    // Else, check its childs
    ListNode *ln = n->myChildList;
    while(ln != NULL)
    {
        Node *n_aux = ln->child;

        n_aux = find_node(n_aux, info, compare_info);

        // If the function returned something other than NULL, it found the node with info.
        if (n_aux != NULL) 
        {
            return n_aux;
        }
        // Else, look for in the next child
        ln = ln->next;
    }

    // If the function failed to find the node, return null.
    return NULL;
}