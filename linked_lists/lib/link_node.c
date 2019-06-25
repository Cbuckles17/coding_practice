#include <stdio.h> 
#include <stdlib.h>
#include "link_node.h"

Link_Node* newLinkNode(int data) 
{ 
	Link_Node *node = (Link_Node*)malloc(sizeof(Link_Node)); 
	node->data = data; 
	node->next = NULL; 
	node->random = NULL;
	node->down = NULL;

	return node; 
}

void pushNewHead(Link_Node **head_ref, int new_data) 
{ 
	Link_Node *new_node = newLinkNode(new_data);
  
	new_node->next = *head_ref; 
  
	*head_ref = new_node; 
} 

void pushNewDown(Link_Node **head_ref, int new_data) 
{ 
    Link_Node* new_node = newLinkNode(new_data);
  
    new_node->down = *head_ref; 

    *head_ref = new_node; 
}

void printList(Link_Node *node) 
{ 
	while (node != NULL) 
    { 
        printf("%d  ", node->data); 
        node = node->next; 
    } 
    printf("\n");  
}

void printListwRandom(Link_Node *node) 
{ 
	Link_Node *holder = node;
	int counter = 0;

	printf("Next-List: ");

    while (node != NULL) 
    { 
        printf("%d  ", node->data); 
        node = node->next; 
        counter++;
    } 
    printf("\nRandom-List: "); 

    while(counter > 0) 
    {  
        holder = holder->random; 
        printf("%d  ", holder->data);
        counter--;
    } 
    printf("\n"); 
}