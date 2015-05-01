#include <stdlib.h>

struct ListNode;

typedef struct Node {
    void *info;
    struct ListNode myChildList;
} Node

typedef struct ListNode {
    Node *this;
    Node *child;
    struct *ListNode next;
} ListNode 

typedef struct {
    size_t sizeInfo;
    Node *root;
} nAryTree

void initializeTree(nAryTree *t, size_t sizeInfo, void *rootInfo);

void addChild(nAryTree *t, void *infoParent, void *infoChild, int (*compare_info)(void *, void *));

Node *create_child(size_t t, void *info);
ListNode *create_list_node();