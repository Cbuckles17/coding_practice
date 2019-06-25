#include <stdio.h> 
#include <stdlib.h>
#include "tree_node.h"

Tree_Node * newTreeNode(int data) 
{ 
	Tree_Node* node = (Tree_Node*)malloc(sizeof(Tree_Node)); 
	node->data = data;
	node->level = 0;
	node->left = NULL; 
	node->right = NULL; 
	node->nextright = NULL;

	return node; 
} 

void printPreOrder(Tree_Node* node) 
{ 
	if(node == NULL) 
	{
		return; 
	}

	printf("%d ", node->data);
	printPreOrder(node->left); 
	printPreOrder(node->right); 	  
}

void printInOrder(Tree_Node* node) 
{ 
	if(node == NULL) 
	{
		return; 
	}

	printInOrder(node->left); 
	printf("%d ", node->data);
	printInOrder(node->right); 	  
}

void printPostOrder(Tree_Node* node) 
{ 
	if(node == NULL) 
	{
		return; 
	}

	printPostOrder(node->left); 
	printPostOrder(node->right); 
	printf("%d ", node->data);  
}