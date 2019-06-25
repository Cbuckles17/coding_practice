#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include "lib/tree_node.h"

d_Bool validate_BST(Tree_Node *root, int last)
{
	if(root == NULL)
	{
		return bool_true;
	}

	d_Bool left = validate_BST(root->left, last);
	//if left returns false then pass it along
	if(!left)
	{
		return bool_false;
	}

	//printf("last: %d now: %d\n", *last, root->data);

	//return false if last is greater or equal to current node
	if(last >= root->data)
	{
		return bool_false;
	}
	else
	{
		last = root->data;
	}

	d_Bool right = validate_BST(root->right, last);
	//if right returns false then pass it along
	if(!right)
	{
		return bool_false;
	}

	return bool_true;
}

void validate_BST_Helper(Tree_Node *root)
{
	int last = INT_MIN;

	if(validate_BST(root, last))
	{
		printf("Valid BST\n");
	}
	else
	{
		printf("Invalid BST\n");
	}
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/bst_validate_in_place bst_validate_in_place.c lib/tree_node.c
//./build/bst_validate_in_place

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