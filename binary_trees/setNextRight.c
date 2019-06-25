#include <stdio.h> 
#include <stdlib.h> 
#include "lib/tree_node.h"
#include "lib/queue.h"

void setNextRight(Tree_Node *root)
{
	Queue_Node *qnode1 = NULL;
	Queue_Node *qnode2 = NULL;
	Queue *q1 = newqueue();
	Queue *q2 = newqueue();

	if(root == NULL)
	{
		return;
	}

	root->level = 1;
	qnode1 = newqueuenode();
	qnode1->value = root;

	pushqueue(q1, qnode1);
	pushqueue(q2, qnode1);

	//this while loop will set the level of all the nodes and make a 2nd queue holding all the nodes
	while(checkemptyqueue(q1) != 0)
	{
		qnode1 = popqueue(q1);

		if(qnode1->value->left != NULL)
		{
			qnode1->value->left->level = qnode1->value->level + 1;
			qnode2 = newqueuenode();
			qnode2->value = qnode1->value->left;
			pushqueue(q1, qnode2);
			pushqueue(q2, qnode2);
		}

		if(qnode1->value->right != NULL)
		{
			qnode1->value->right->level = qnode1->value->level + 1;
			qnode2 = newqueuenode();
			qnode2->value = qnode1->value->right;
			pushqueue(q1, qnode2);
			pushqueue(q2, qnode2);
		}
	}

	//compare the top 2 nodes in the queue for their levels
	qnode1 = popqueue(q2);
	while(checkemptyqueue(q2) != 0)
	{
		qnode2 = popqueue(q2);

		//printf("level compare: qnode1 - %d qnode2 - %d\n", qnode1->value->level, qnode2->value->level);
		if(qnode1->value->level == qnode2->value->level)
		{
			qnode1->value->nextright = qnode2->value;
		}
		else
		{
			qnode1->value->nextright = NULL;
		}

		qnode1 = qnode2;
	}

	//set the last node in the tree
	//or this catches a tree with only root
	qnode1->value->nextright = NULL;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/setNextRight setNextRight.c lib/tree_node.c lib/queue.c
//./build/setNextRight

//gcc -o setNextRight setNextRight.c queue.c
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
	
	setNextRight(root);

	printf("Following are populated nextright pointers in the tree (-1 is printed if there is no nextright) \n"); 
	printf("nextright of %d is %d \n", root->data, root->nextright? root->nextright->data: -1); 
	printf("nextright of %d is %d \n", root->left->data, root->left->nextright? root->left->nextright->data: -1); 
	printf("nextright of %d is %d \n", root->right->data, root->right->nextright? root->right->nextright->data: -1); 
	printf("nextright of %d is %d \n", root->left->left->data, root->left->left->nextright? root->left->left->nextright->data: -1);
	printf("nextright of %d is %d \n", root->left->right->data, root->left->right->nextright? root->left->right->nextright->data: -1);
	printf("nextright of %d is %d \n", root->right->left->data, root->right->left->nextright? root->right->left->nextright->data: -1);
	printf("nextright of %d is %d \n", root->right->right->data, root->right->right->nextright? root->right->right->nextright->data: -1);
	printf("nextright of %d is %d \n", root->left->left->right->data, root->left->left->right->nextright? root->left->left->right->nextright->data: -1);
	printf("nextright of %d is %d \n", root->right->right->left->data, root->right->right->left->nextright? root->right->right->left->nextright->data: -1);

	/* Constructed binary tree is 
              10 
            /   \ 
          8      2 
        /         \ 
      3            90 
    */
    Tree_Node* root2 = newTreeNode(10); 
    root2->left = newTreeNode(8); 
    root2->right = newTreeNode(2); 
    root2->left->left = newTreeNode(3); 
    root2->right->right = newTreeNode(90); 
  
    setNextRight(root2);
  
	printf("Following are populated nextright pointers in the tree (-1 is printed if there is no nextright) \n"); 
	printf("nextright of %d is %d \n", root2->data, root2->nextright? root2->nextright->data: -1); 
	printf("nextright of %d is %d \n", root2->left->data, root2->left->nextright? root2->left->nextright->data: -1); 
	printf("nextright of %d is %d \n", root2->right->data, root2->right->nextright? root2->right->nextright->data: -1); 
	printf("nextright of %d is %d \n", root2->left->left->data, root2->left->left->nextright? root2->left->left->nextright->data: -1);
	printf("nextright of %d is %d \n", root2->right->right->data, root2->right->right->nextright? root2->right->right->nextright->data: -1);

	return 0;
}