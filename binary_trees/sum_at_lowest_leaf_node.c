#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include "lib/tree_node.h"

void sumatleaf(Tree_Node *root, int *levelat, int sumgoal, int clevel, int csum)
{	
	//we are at a leaf so check if the csum == sumgoal
	if(root == NULL)
	{
		//printf("Sum at leaf node level: %d\n", csum);

		if(csum == sumgoal)
		{	
			*levelat = clevel;
			printf("Sum is equal to goal at leaf node level: %d\n", *levelat);
		}

		return;
	}

	//no point in continuing if we are past a known min level or past the sumgoal
	if(clevel < *levelat && csum < sumgoal)
	{
		clevel++;
		csum+=root->data;
	}
	else
	{
		return;
	}

	sumatleaf(root->left, levelat, sumgoal, clevel, csum);
	sumatleaf(root->right, levelat, sumgoal, clevel, csum);

	return;
}

int sumatleaf_helper(Tree_Node *root, int sumgoal)
{
	int levelat = INT_MAX;
	int csum = 0;
	int clevel = 0;

	sumatleaf(root, &levelat, sumgoal, clevel, csum);

	return levelat;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/sum_at_lowest_leaf_node sum_at_lowest_leaf_node.c lib/tree_node.c
//./build/sum_at_lowest_leaf_node

int main()
{
	/* Constructed binary tree is 
	        10 
	      /   \ 
	    8      2 
	  /  \    / 
	3     5  2 
	*/
	Tree_Node *root = newTreeNode(10); 
	root->left        = newTreeNode(8); 
	root->right       = newTreeNode(2); 
	root->left->left  = newTreeNode(3); 
	root->left->right = newTreeNode(5); 
	root->right->left = newTreeNode(2); 

	int sum1 = 21; 

	printf("sum: %d lowest level: %d\n", sum1, sumatleaf_helper(root, sum1));

	printf("--------\n");


	//            10
	//       8           2
	//    3     1     5     27
	//      18            0

	Tree_Node *root2 = newTreeNode(10); 
	root2->left        = newTreeNode(8); 
	root2->right       = newTreeNode(2);
	root2->left->left  = newTreeNode(3); 
	root2->left->right  = newTreeNode(1); 
	root2->right->left  = newTreeNode(5); 
	root2->right->right  = newTreeNode(27);
	root2->left->left->right  = newTreeNode(18); 
	root2->right->right->left  = newTreeNode(0); 

	int sum2 = 39; 

	printf("sum: %d lowest level: %d\n", sum2, sumatleaf_helper(root2, sum2));

	printf("--------\n");

	int sum3 = 2; 

	printf("sum: %d lowest level: %d\n", sum3, sumatleaf_helper(root2, sum3));

	printf("--------\n");

	int sum4 = 16; 

	/* Constructed binary tree is  
	      
	             1 
	         /       \  
	      10         15  
	   /      \      
	 5        2  
	*/
	Tree_Node *root3 = newTreeNode(1); 
	root3->left = newTreeNode(10); 
	root3->right = newTreeNode(15); 
	root3->left->left = newTreeNode(5); 
	root3->left->right = newTreeNode(2); 

	printf("sum: %d lowest level: %d\n", sum4, sumatleaf_helper(root3, sum4));
}