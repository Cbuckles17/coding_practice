#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
#include "lib/path_root_to_node.h"

int LCA(Tree_Node *root, int num1, int num2)
{
	int LCA = INT_MIN;
	int c1 = INT_MIN;
	int c2 = INT_MIN;
	Link_Node *path1 = NULL;
	Link_Node *path2 = NULL;

	pathToNode(root, &path1, num1);
	//printList(path1);
	//printf("-----------------\n");
	pathToNode(root, &path2, num2);
	//printList(path2);
	//printf("-----------------\n");

	//loop through the two paths and find the last point in which their paths collide
	while(path1 != NULL && path2 != NULL)
	{
		c1 = path1->data;
		c2 = path2->data;

		if(c1 == c2)
		{
			LCA = c1;
		}

		path1 = path1->next;
		path2 = path2->next;
	}

	return LCA;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/least_common_ancestor least_common_ancestor.c lib/tree_node.c ../linked_lists/lib/link_node.c path_root_to_node.c
//./build/least_common_ancestor

int main()
{
	//            10
	//       8           2
	//    3     1     5     6
	//      18            0

	Tree_Node *root = newTreeNode(10); 
	root->left        = newTreeNode(8); 
	root->right       = newTreeNode(2);
	root->left->left  = newTreeNode(3); 
	root->left->right  = newTreeNode(1); 
	root->right->left  = newTreeNode(5); 
	root->right->right  = newTreeNode(6);
	root->left->left->right  = newTreeNode(18); 
	root->right->right->left  = newTreeNode(0); 

	int ret1 = LCA(root, 8, 1);
	printf("LCA = %d\n", ret1);
	printf("-----------------\n");
	int ret2 = LCA(root, 18, 0);
	printf("LCA = %d\n", ret2);
	printf("-----------------\n");
	int ret3 = LCA(root, 5, 6);
	printf("LCA = %d\n", ret3);
	printf("-----------------\n");
	int ret4 = LCA(root, 10, 6);
	printf("LCA = %d\n", ret4);
	printf("-----------------\n");
	int ret5 = LCA(root, 11, 6);
	printf("LCA = %d\n", ret5);
	printf("-----------------\n");

	Tree_Node * root2 = newTreeNode(1); 
    root2->left = newTreeNode(2); 
    root2->right = newTreeNode(3); 
    root2->left->left = newTreeNode(4); 
    root2->left->right = newTreeNode(5); 
    root2->right->left = newTreeNode(6); 
    root2->right->right = newTreeNode(7); 

    int ret6 = LCA(root2, 4, 5);
	printf("LCA = %d\n", ret6);
	printf("-----------------\n");
	int ret7 = LCA(root2, 4, 6);
	printf("LCA = %d\n", ret7);
	printf("-----------------\n");
	int ret8 = LCA(root2, 3, 4);
	printf("LCA = %d\n", ret8);
	printf("-----------------\n");
	int ret9 = LCA(root2, 2, 4);
	printf("LCA = %d\n", ret9);

	return 0;
}