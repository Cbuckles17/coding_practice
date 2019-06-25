#include <stdio.h> 
#include <stdlib.h> 
#include "lib/link_node.h"

int add_ll(Link_Node *node1, Link_Node*node2, Link_Node **node3)
{
	if(node1 == NULL) //at end so carrybit is 0
	{
		return 0;
	}

	int carrybit = add_ll(node1->next, node2->next, node3);
	int added = carrybit + node1->data + node2->data;

	if(added / 10 != 0) //we have a carrybit
	{
		pushNewHead(node3, added % 10);
		return 1;
	}
	else
	{
		pushNewHead(node3, added);
		return 0;
	}
}

void add_ll_runner(Link_Node *node1, Link_Node *node2, Link_Node **node3)
{
	if(add_ll(node1, node2, node3) == 1) //ending carrybit
	{
		pushNewHead(node3, 1) ;
	}
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/linked_list_addition linked_list_addition.c lib/link_node.c
//./build/linked_list_addition

int main() 
{ 
  	Link_Node *head1 = NULL;
    Link_Node *head2 = NULL;
    Link_Node *result = NULL; 
  	int i = 0;
  	
  	//assuming that we have equal length lists
    int arr1[] = {9, 9, 9}; //999
    int arr2[] = {1, 8, 0}; //180     =   1179
 
    for (i = 2; i >= 0; --i) 
    {
        pushNewHead(&head1, arr1[i]); 
    }

    for (i = 2; i >= 0; --i) 
    {
       	pushNewHead(&head2, arr2[i]);
    }

    add_ll_runner(head1, head2, &result);

    printList(result);

    head1 = NULL;
    head2 = NULL;
    result = NULL;

    //assuming that we have equal length lists
    int arr3[] = {3, 8, 1, 7, 6, 8}; //381768
    int arr4[] = {8, 2, 9, 2, 3, 1}; //829231     =   1210999
 
    for (i = 5; i >= 0; --i) 
    {
        pushNewHead(&head1, arr3[i]); 
    }

    for (i = 5; i >= 0; --i) 
    {
       	pushNewHead(&head2, arr4[i]);
    }

    add_ll_runner(head1, head2, &result);

    printList(result);
      
  return 0; 
}