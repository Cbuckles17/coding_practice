#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include "lib/tree_node.h"

int swapBST(Tree_Node *root, int last_data, Tree_Node **last_node, Tree_Node **saved)
{
	if(root == NULL)
	{
		return 0;
	}

	int checkleft = swapBST(root->left, last_data, last_node, saved);
	if(checkleft == 1)
	{
		return 1;
	}

	//printf("Current Node: %d and Last Data: %d\n", root->data, *last_data);

	//first instance of a error in the BST
	//so the last node is from the right side of the swap i.e the larger number
	//the inorder node is the root in this case. so save that as the last
	if(last_data > root->data && *saved == NULL)
	{
		//printf("Found Right Swap: %d\n", (*last_node)->data);

		*saved = *last_node;
		*last_node = root;
		last_data = root->data;
	}
	//second instance of an error in the BST
	//so the root is from the left side of the swap i.e the smaller number
	else if(last_data > root->data)
	{
		//printf("Found Left Swap: %d\n", root->data);

		int holder = root->data;
		root->data = (*saved)->data;
		(*saved)->data = holder;

		//lets exit now since we've made the swap
		return 1;
	}
	//everything is fine so save off the last node
	else
	{
		*last_node = root;
		last_data = root->data;
	}

	int checkright = swapBST(root->right, last_data, last_node, saved);
	if(checkright == 1)
	{
		return 1;
	}

	//if we got to here then everything is fine
	return 0;
}

void swapBST_Helper(Tree_Node *root)
{
	int last_data = INT_MIN;
	Tree_Node *last_node = NULL;
	Tree_Node *saved = NULL;

	printf("\n");
	printInOrder(root);

	if(swapBST(root, last_data, &last_node, &saved) == 1)
	{
		printf("\nBST Tree Fixed\n");
		printInOrder(root);
	}
	else
	{
		printf("\nBST Tree was fine\n");
	}

	printf("\n");
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/swap_BST swap_BST.c lib/tree_node.c
//./build/swap_BST

int main() 
{ 
	Tree_Node *root = newTreeNode(4); 
	root->left        = newTreeNode(2); 
	root->right       = newTreeNode(5); 
	root->left->left  = newTreeNode(1); 
	root->left->right = newTreeNode(3);  

	swapBST_Helper(root);

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

    swapBST_Helper(root2);

    Tree_Node *root3 = newTreeNode(4); 
	root3->left        = newTreeNode(2); 
	root3->right       = newTreeNode(1); 
	root3->left->left  = newTreeNode(5); 
	root3->left->right = newTreeNode(3);  

	swapBST_Helper(root3);
	  
	return 0; 
}