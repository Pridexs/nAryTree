#include "nary_tree.h"

#include <string.h>

int initializeTree(nAryTree *t, size_t sizeInfo, void *root_info)
{
    t->sizeInfo = sizeInfo;
    t->root = create_child(sizeInfo, root_info);
    return SUCCESS;
}

/*******************************************************
* Finds a node with the same infomration as infoParent * 
* and adds a child to that node                        *
********************************************************/
int add_child(nAryTree *t, void *infoParent, void *infoChild, int (*compare_info)(void *, void *))
{
    Node *n;

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
        {
            free(n->myChildList);
            n->myChildList = NULL;
            return ERROR;
        }
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
        {
            free(ln->next);
            ln->next = NULL;
            return ERROR;
        }
    }

    return SUCCESS;
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

/*****************************************
* Prints the tree using pre-order method *
******************************************/
void *print_pre_order(nAryTree *t, void (*print_info)(void *))
{
    Node *n = t->root;
    print_pre_order_nodes(n, print_info);
}

void *print_pre_order_nodes(Node *n, void (*print_info)(void *))
{
    print_info(n->info);

    ListNode *ln = n->myChildList;
    while(ln != NULL)
    {
        Node *n_aux = ln->child;
        print_pre_order_nodes(n_aux, print_info);
        ln = ln->next;
    }
}

int remove_node(nAryTree *t, void *info, void *removed, int (*compare_info)(void*,void*)))
{
	Node *n_aux = find_node(t->root, info, compare_info);
	if(n_aux == NULL)
		return ERROR_NODE_NOT_FOUND;
	memcpy(removed, n_aux, t->sizeInfo);
	if (n_aux != t->root)
		ListNode *ln = find_child_list(t->root, NULL, info, compare_info);
	if(ln == NULL)
		return ERROR;
	ListNode *l_prev = NULL;
	while(ln->child != n_aux)
	{
		l_prev = ln;
		ln = ln->next;
	}
	l_prev->next = ln->next;
	free(ln->child);
	free(ln);
}

ListNode *find_child_list(Node *n, ListNode *ln, void *info,int(*compare_info)(void*, void*))
{
	/*the first time that this function is executed ln is passed as a
	  NULL pointer*/
	/*a good option before trying to find the list that the node is in,
	  is to verify if the node is the rootof the tree, if this verification 
	  wasnt made, this function will return NULL if the node is root or
	  it doesnt even exists.*/
	if (compare_info(n->info, info) == 0) 
    {
        return ln;
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
            return ln;
        }
        // Else, look for in the next child
        ln = ln->next;
    }

    // If the function failed to find the list, return null.
    return NULL;
}