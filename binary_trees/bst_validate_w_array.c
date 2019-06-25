#include <stdio.h> 
#include <stdlib.h> 
#include "lib/tree_node.h"
  
void inorder_BST(Tree_Node *root, int *counter, int **bst_array)
{
	if(root == NULL)
	{
		return;
	}

	inorder_BST(root->left, counter, bst_array);
	(*bst_array)[++(*counter)] = root->data;
	inorder_BST(root->right, counter, bst_array);
}

int validate_BST(int counter, int *bst_array)
{
	while(counter > 0)
	{
		//printf("right: %d left: %d\n", bst_array[counter], bst_array[counter - 1]);

		if(bst_array[counter] <= bst_array[counter - 1])
		{
			return 0;
		}

		counter--;
	}

	return 1;
}

void validate_BST_Helper(Tree_Node *root)
{
	//magic number of 100. Just assuming we wont have above a value of 100
	int *bst_array = (int *)calloc(100, sizeof(int));
	int counter = -1;

	inorder_BST(root, &counter, &bst_array);

	if(validate_BST(counter, bst_array) == 1)
	{
		printf("Valid BST\n");
	}
	else
	{
		printf("Invalid BST\n");
	}

	free(bst_array);
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/bst_validate_w_array bst_validate_w_array.c lib/tree_node.c
//./build/bst_validate_w_array

int main() 
{ 
  	Tree_Node *root = newTreeNode(4); 
	root->left        = newTreeNode(2); 
	root->right       = newTreeNode(5); 
	root->left->left  = newTreeNode(1); 
	root->left->right = newTreeNode(3);  

	printInOrder(root);
	validate_BST_Helper(root);

	/*   6 
        /  \ 
       10    2 
      / \   / \ 
     1   3 7  12 
     10 and 2 are swapped 
    */
  
    Tree_Node *root2 = newTreeNode(6); 
    root2->left        = newTreeNode(10); 
    root2->right       = newTreeNode(2); 
    root2->left->left  = newTreeNode(1); 
    root2->left->right = newTreeNode(3); 
    root2->right->right = newTreeNode(12); 
    root2->right->left = newTreeNode(7);

    printInOrder(root2);
    validate_BST_Helper(root2);
      
  return 0; 
}

