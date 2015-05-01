#include <stdlib.h>

#define SUCCESS 0
#define ERROR 1
#define ERROR_PARENT_NOT_FOUND 2

struct ListNode;

typedef struct Node {
    void *info;
    struct ListNode myChildList;
} Node;

typedef struct ListNode {
    Node *child;
    struct *ListNode next;
} ListNode;

typedef struct {
    size_t sizeInfo;
    Node *root;
} nAryTree;

void initializeTree(nAryTree *t, size_t sizeInfo, void *rootInfo);
void add_child(nAryTree *t, void *infoParent, void *infoChild, int (*compare_info)(void *, void *))

Node *find_node(Node *n, void *info, int (*compare_info)(void *, void *))
Node *create_child(size_t t, void *info);
ListNode *create_list_node();