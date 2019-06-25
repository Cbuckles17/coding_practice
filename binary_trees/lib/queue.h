#ifndef HEADER_QUEUE
#define HEADER_QUEUE

#include "tree_node.h"

typedef struct queuenode
{
	struct queuenode *next;
	Tree_Node *value;
} Queue_Node;

typedef struct queue 
{ 
	int size;
	Queue_Node *head; 
	Queue_Node *tail; 
} Queue;

Queue_Node * newqueuenode();
Queue * newqueue();
int checkemptyqueue(Queue *q);
Queue_Node* popqueue(Queue *q);
void pushqueue(Queue *q, Queue_Node *topush);

#endif