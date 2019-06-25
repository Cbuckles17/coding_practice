#ifndef HEADER_TREE_NODE
#define HEADER_TREE_NODE

typedef enum 
{
	bool_false = 0,
	bool_true
} d_Bool;

typedef struct tree_node 
{ 
	int data; 
	int level;
	struct tree_node* left; 
	struct tree_node* right; 
	struct tree_node* nextright;
} Tree_Node;

Tree_Node * newTreeNode(int data);
void printPreOrder(Tree_Node* node);
void printInOrder(Tree_Node* node);
void printPostOrder(Tree_Node* node);

#endif