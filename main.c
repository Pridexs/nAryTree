#include <stdlib.h>
#include <stdio.h>

#include "nary_tree.h"

int compare_int(void *a, void *b)
{
	int *a_int = (int*) a;
	int *b_int = (int*) b;

	return (*a_int) == (*b_int);
}

void print_integer(void *a)
{
	int *a_int = (int*) a;
	printf("%d ", *a_int);
}

int main()
{
	nAryTree tree;

	int root = 0;

	initializeTree(&tree, sizeof(int), &root);

	int infoChild = 1;
	add_child(&tree, &root, &infoChild, compare_int);

	infoChild = 2;
	add_child(&tree, &root, &infoChild, compare_int);

	root = 1;
	infoChild = 3;
	add_child(&tree, &root, &infoChild, compare_int);

	print_pre_order(&tree, print_integer);

	return 0;
}