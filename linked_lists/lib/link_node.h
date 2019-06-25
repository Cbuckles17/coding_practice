#ifndef HEADER_LINK_NODE
#define HEADER_LINK_NODE

typedef struct link_node 
{ 
	int data; 
	struct link_node* next; 
	struct link_node* random;
	struct link_node* down;
} Link_Node;

Link_Node* newLinkNode(int data);
void pushNewHead(Link_Node **head_ref, int new_data);
void pushNewDown(Link_Node **head_ref, int new_data);
void printList(Link_Node *node);
void printListwRandom(Link_Node *node);

#endif