#include <stdio.h> 
#include <stdlib.h> 
#include "queue.h"

Queue_Node * newqueuenode() 
{ 
	Queue_Node* node = (Queue_Node*)malloc(sizeof(Queue_Node)); 
	node->next = NULL; 
	node->value = NULL; 

	return(node); 
} 

Queue * newqueue() 
{ 
	Queue* q = (Queue*)malloc(sizeof(Queue)); 
	q->size = 0;
	q->head = NULL; 
	q->tail = NULL; 

	return(q); 
} 

int checkemptyqueue(Queue *q)
{
	if(q->size == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

Queue_Node* popqueue(Queue *q)
{
	Queue_Node *topop = NULL;

	if(checkemptyqueue(q) != 0)
	{
		topop = q->head;
		q->head = q->head->next;
		q->size--;
		return topop;
	}
	else
	{
		printf("Trying to pop empty queue\n");
		return NULL;
	}
}

void pushqueue(Queue *q, Queue_Node *topush)
{
	if(checkemptyqueue(q) == 0)
	{
		//printf("Queue is Empty in pushqueue\n");
		q->head = topush;
	}
	else
	{
		//printf("Queue is Not Empty in pushqueue\n");
		q->tail->next = topush;
	}

	q->tail = topush;
	q->size++;
}







