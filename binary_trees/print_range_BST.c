#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include "lib/tree_node.h"

int printrangeBST(Tree_Node *root, int low, int high)
{
	if(root == NULL)
	{
		return 0;
	}

	int left = printrangeBST(root->left, low, high);
	if(left == 1)
	{
		//we went past the upper limit no need to continue
		return 1;
	}

	if(root->data >= low && root->data <= high)
	{
		printf("Node data = %d\n", root->data);
	}
	//if we went past the range no point in continuing
	else if(root->data > high)
	{
		return 1;
	}

	int right = printrangeBST(root->right, low, high);
	if(right == 1)
	{
		//we went past the upper limit no need to continue
		return 1;
	}

	return 0;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/print_range_BST print_range_BST.c lib/tree_node.c
//./build/print_range_BST

int main() 
{ 
	Tree_Node *root = newTreeNode(4); 
	root->left        = newTreeNode(2); 
	root->right       = newTreeNode(5); 
	root->left->left  = newTreeNode(1); 
	root->left->right = newTreeNode(3);  

	printrangeBST(root, 3, 5);

	printf("---------------\n");

	/*   6 
        /  \ 
       2    10 
      / \   / \ 
     1   3 7  12 
    */
  
    Tree_Node *root2 = newTreeNode(6); 
    root2->left        = newTreeNode(2); 
    root2->right       = newTreeNode(10); 
    root2->left->left  = newTreeNode(1); 
    root2->left->right = newTreeNode(3); 
    root2->right->right = newTreeNode(12); 
    root2->right->left = newTreeNode(7);

    printrangeBST(root2, 2, 7);

    printf("---------------\n");

    Tree_Node *root3 = newTreeNode(20); 
	root3->left = newTreeNode(8); 
	root3->right = newTreeNode(22); 
	root3->left->left = newTreeNode(4); 
	root3->left->right = newTreeNode(12); 

	printrangeBST(root3, 10, 25);
	  
	return 0; 
}