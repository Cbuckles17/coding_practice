#include <stdio.h> 
#include <stdlib.h> 
#include "../linked_lists/lib/link_node.h"
#include "lib/path_root_to_node.h"

int pathToNode(Tree_Node *root, Link_Node **path, int num)
{
	if(root == NULL)
	{
		return 0;
	}

	if(num == root->data)
	{
		//printf("Found num: %d\n", root->data);
		pushNewHead(path, root->data);
		return 1;
	}

	int checkL = pathToNode(root->left, path, num);
	if(checkL == 1)
	{
		//printf("Found Path Left: %d\n", root->data);
		pushNewHead(path, root->data);
		return 1;
	}

	int checkR = pathToNode(root->right, path, num);
	if(checkR == 1)
	{
		//printf("Found Path Right: %d\n", root->data);
		pushNewHead(path, root->data);
		return 1;
	}

	//no path if we got to here
	return 0;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/path_root_to_node path_root_to_node.c lib/tree_node.c ../linked_lists/lib/link_node.c
//./build/path_root_to_node

// int main()
// {
// 	//            10
// 	//       8           2
// 	//    3     1     5     6
// 	//      18            0

// 	Tree_Node *root = newTreeNode(10); 
// 	root->left        = newTreeNode(8); 
// 	root->right       = newTreeNode(2);
// 	root->left->left  = newTreeNode(3); 
// 	root->left->right  = newTreeNode(1); 
// 	root->right->left  = newTreeNode(5); 
// 	root->right->right  = newTreeNode(6);
// 	root->left->left->right  = newTreeNode(18); 
// 	root->right->right->left  = newTreeNode(0); 

// 	Link_Node *path1 = NULL;
// 	Link_Node *path2 = NULL;
// 	Link_Node *path3 = NULL;
// 	Link_Node *path4 = NULL;
// 	Link_Node *path5 = NULL;

// 	pathToNode(root, &path1, 5);

// 	printList(path1);

// 	printf("-----------------\n");

// 	pathToNode(root, &path2, 18);

// 	printList(path2);

// 	printf("-----------------\n");

// 	pathToNode(root, &path3, 10);

// 	printList(path3);

// 	printf("-----------------\n");

// 	pathToNode(root, &path4, 9);

// 	printList(path4);

// 	printf("-----------------\n");

// 	pathToNode(root, &path5, 2);

// 	printList(path5);

// 	return 0;
// }