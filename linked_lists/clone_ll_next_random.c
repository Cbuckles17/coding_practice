#include <stdio.h> 
#include <stdlib.h> 
#include "lib/link_node.h"

void clone_ll(Link_Node *list1head, Link_Node **list2head)
{
	Link_Node *list1c = list1head;
	Link_Node *list1n = NULL;
	Link_Node *list2c = NULL;

	if(list1c == NULL)
	{
		printf("empty list given\n");
		return;
	}
	else
	{
		//clone the current node
		list2c = newLinkNode(list1c->data);
		//save off the head 
		*list2head = list2c;
	}
	
	//clone the old->next and set that to current->next
	//set current->random to the old
	//save off old->next so we can get back to it
	//set old->next to the current
	//restore the saved off old->next
	//move to current->next
	while(list1c != NULL)
	{
		//clone the current node's next if it exists
		if(list1c->next != NULL)
		{
			list2c->next = newLinkNode(list1c->next->data);
		}
		//set the new node random to the current node
		list2c->random = list1c;
		//save off the current nodes next
		list1n = list1c->next;
		//set the current node next to the new node
		list1c->next = list2c;
		//move to next node
		list1c = list1n;
		list2c = list2c->next;
	}

	//reset to the head
	list2c = *list2head;

	//at this point the current->random points to the old node
	//the old node->random points to another old node
	//old node->next points to a current node
	//so just cut out the middle man
	while(list2c != NULL)
	{	
		//set the random to the old nodes random. The next of the old nodes points to the new nodes
		list2c->random = list2c->random->random->next;
		list2c = list2c->next;
	}
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/clone_ll_next_random clone_ll_next_random.c lib/link_node.c
//./cbuild/lone_ll_next_random

int main() 
{ 
  	Link_Node *result = NULL; 

    Link_Node* head = newLinkNode(9); 
    head->next = newLinkNode(8); 
    head->next->next = newLinkNode(7); 

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;

    printListwRandom(head);
    clone_ll(head, &result);
    printListwRandom(result);

    return 0;
}