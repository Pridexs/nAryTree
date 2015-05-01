#include <stdlib.h>

#define SUCCESS 0
#define ERROR 1
#define ERROR_PARENT_NOT_FOUND 2
#define ERROR_NODE_NOT_FOUND 3

struct _Node;

typedef struct _ListNode {
    struct _Node *child;
    struct _ListNode *next;
} ListNode;

typedef struct _Node {
    void *info;
    ListNode *myChildList;
} Node;


typedef struct {
    size_t sizeInfo;
    Node *root;
} nAryTree;

int initializeTree(nAryTree *t, size_t sizeInfo, void *root_info);
int add_child(nAryTree *t, void *infoParent, void *infoChild, int (*compare_info)(void *, void *));
int remove_node(nAryTree *t, void *info, void *removed, int (*compare_info)(void*,void*));

void *print_pre_order(nAryTree *t, void (*print_info)(void *));
void *print_pre_order_nodes(Node *n, void (*print_info)(void *));

Node *find_node(Node *n, void *info, int (*compare_info)(void *, void *));
Node *create_child(size_t t, void *info);
ListNode *create_list_node();
ListNode *find_child_list(Node *n, ListNode *ln, void *info,int(*compare_info)(void*, void*));
