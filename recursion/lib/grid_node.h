#ifndef HEADER_GRID_NODE
#define HEADER_GRID_NODE

typedef struct grid_node 
{ 
	int row;
	int col; 
	struct grid_node* next;
} Grid_Node;

Grid_Node* newGridNode(int row, int col);
void pushNewHead(Grid_Node **head_ref, int row, int col);
void printList(Grid_Node *node);

#endif