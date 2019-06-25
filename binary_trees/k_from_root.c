#include <stdio.h> 
#include <stdlib.h>
#include "lib/tree_node.h" 

void kfromroot(Tree_Node *root, int atlevel, int k)
{
	if(root == NULL)
	{
		return;
	}

	if(atlevel == k)
	{
		printf("Node %d at level %d\n", root->data, atlevel);
		return;
	}
	//no point in going past this level
	else if(atlevel > k)
	{
		return;
	}

	kfromroot(root->left, atlevel + 1, k);
	kfromroot(root->right, atlevel + 1, k);

	return;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/k_from_root k_from_root.c lib/tree_node.c
//./build/k_from_root

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
	
	//root is considered level 0
	kfromroot(root, 0, 0);
	printf("--------\n");
	kfromroot(root, 0, 1);
	printf("--------\n");
	kfromroot(root, 0, 2);
	printf("--------\n");
	kfromroot(root, 0, 3);
	printf("--------\n");
	kfromroot(root, 0, 4);
	printf("--------\n");

	/* Constructed binary tree is  
            1  
            / \  
        2    3  
        / \  /  
        4 5 8  
    */
    Tree_Node *root2 = newTreeNode(1);  
    root2->left = newTreeNode(2);  
    root2->right = newTreeNode(3);  
    root2->left->left = newTreeNode(4);  
    root2->left->right = newTreeNode(5);  
    root2->right->left = newTreeNode(8);

    //root is considered level 0
	kfromroot(root2, 0, 0);
	printf("--------\n");
	kfromroot(root2, 0, 1);
	printf("--------\n");
	kfromroot(root2, 0, 2);
	printf("--------\n");
	kfromroot(root2, 0, 3);
}