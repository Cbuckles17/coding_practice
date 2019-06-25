#include <stdio.h> 
#include <stdlib.h>
#include "lib/tree_node.h" 

int sumBT(Tree_Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	int oldval = root->data;
	root->data = sumBT(root->left) + sumBT(root->right);

	return oldval + root->data;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/sum_BT sum_BT.c lib/tree_node.c
//./build/sum_BT

int main()
{
	Tree_Node *root = newTreeNode(4); 
	root->left        = newTreeNode(2); 
	root->right       = newTreeNode(5); 
	root->left->left  = newTreeNode(1); 
	root->left->right = newTreeNode(3); 
	printf("Sum of the Tree = %d\n", sumBT(root));
    printPostOrder(root);
    printf("\n-------\n");

	/*   6 
        /  \ 
       10    2 
      / \   / \ 
     1   3 7  12 
    */
  
    Tree_Node *root2 = newTreeNode(6); 
    root2->left        = newTreeNode(10); 
    root2->right       = newTreeNode(2); 
    root2->left->left  = newTreeNode(1); 
    root2->left->right = newTreeNode(3); 
    root2->right->right = newTreeNode(12); 
    root2->right->left = newTreeNode(7);

    printf("Sum of the Tree = %d\n", sumBT(root2));
    printPostOrder(root2);

	return 0;
}