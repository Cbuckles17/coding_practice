#include <stdio.h> 
#include <stdlib.h>
#include "grid_node.h"

Grid_Node* newGridNode(int row, int col)
{ 
	Grid_Node *node = (Grid_Node*)malloc(sizeof(Grid_Node)); 
	node->row = row; 
    node->col = col; 
	node->next = NULL; 

	return node; 
}

void pushNewHead(Grid_Node **head_ref, int row, int col) 
{ 
	Grid_Node *new_node = newGridNode(row, col);
  
	new_node->next = *head_ref; 
  
	*head_ref = new_node; 
} 

void printList(Grid_Node *node)
{ 
	while (node != NULL) 
    { 
        printf("(%d,%d) ", node->row, node->col); 
        node = node->next; 
    } 
    printf("\n");  
}
