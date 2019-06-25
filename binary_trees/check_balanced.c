#include <stdio.h> 
#include <stdlib.h> 
#include "lib/tree_node.h"

int checkbalanced(Tree_Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	int leftcheck = checkbalanced(root->left);
	if(leftcheck == -1)
	{
		return leftcheck;
	}
	else
	{
		//add to our level counter
		leftcheck = leftcheck + 1;
	}

	int rightcheck = checkbalanced(root->right);
	if(rightcheck == -1)
	{
		return rightcheck;
	}
	else
	{
		//add to our level counter
		rightcheck = rightcheck + 1;
	}

	// //this is how you would check for a perfect tree
	// if(leftcheck != rightcheck)
	// {
	// 	return -1;
	// }
	// else
	// {
	// 	//could return left or right..theyre the same value
	// 	return leftcheck;
	// }

	//check the difference between the two sides and see if they differ by more than 1
	if(abs(leftcheck - rightcheck) > 1)
	{
		return -1;
	}
	//return the deeper of the two sides
	else if(leftcheck > rightcheck)
	{
		return leftcheck;
	}
	else
	{
		return rightcheck;
	}
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/check_balanced check_balanced.c lib/tree_node.c
//./build/check_balanced

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

	if(checkbalanced(root) == - 1)
	{
		printf("Unbalanced Tree\n");
	}
	else
	{
		printf("Balanced Tree\n");
	}

	Tree_Node * root2 = newTreeNode(1); 
    root2->left = newTreeNode(2); 
    root2->right = newTreeNode(3); 
    root2->left->left = newTreeNode(4); 
    root2->left->right = newTreeNode(5); 
    root2->right->left = newTreeNode(6); 
    root2->right->right = newTreeNode(7); 

    if(checkbalanced(root2) == - 1)
	{
		printf("Unbalanced Tree\n");
	}
	else
	{
		printf("Balanced Tree\n");
	}

	Tree_Node *root3 = newTreeNode(1); 
    root3->left = newTreeNode(2); 
    root3->right = newTreeNode(3); 
    root3->left->left = newTreeNode(4); 
    root3->left->right = newTreeNode(5); 
    root3->left->left->left = newTreeNode(8); 

    if(checkbalanced(root3) == - 1)
	{
		printf("Unbalanced Tree\n");
	}
	else
	{
		printf("Balanced Tree\n");
	}

	/* Constructed binary tree is 
	         1 
	       /   \ 
	     2      3 
	   /  \    / 
	 4     5  6 
	/ 
	7 
	*/ 
	
	Tree_Node *root4 = newTreeNode(1);   
	root4->left = newTreeNode(2); 
	root4->right = newTreeNode(3); 
	root4->left->left = newTreeNode(4); 
	root4->left->right = newTreeNode(5); 
	root4->right->left = newTreeNode(6); 
	root4->left->left->left = newTreeNode(7); 

	if(checkbalanced(root4) == - 1)
	{
		printf("Unbalanced Tree\n");
	}
	else
	{
		printf("Balanced Tree\n");
	}

	return 0;
}