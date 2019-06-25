#include <stdio.h> 
#include <stdlib.h> 
#include "lib/link_node.h"

void deleteMiddle(Link_Node **listref)
{
	if(*listref == NULL)
	{
		return;
	}
	else if((*listref)->next == NULL)
	{
		printf("Freeing node with data: %d\n", (*listref)->data);
		free(*listref);
		*listref = NULL;
		return;
	}

	Link_Node *fast = *listref;
	Link_Node *slow = *listref;
	Link_Node *slower = NULL;

	//if fast is null that means even list
	//if fast->next is null that means odd list
	while(fast != NULL && fast->next != NULL)
	{
		slower = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	slower->next = slow->next;

	//free the middle node
	//if even this frees the right middle node
	printf("Freeing node with data: %d\n", slow->data);
	free(slow);
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/delete_middle_ll delete_middle_ll.c lib/link_node.c
//./build/delete_middle_ll

int main() 
{ 
	Link_Node* head = newLinkNode(1); 
    head->next = newLinkNode(2); 
    head->next->next = newLinkNode(3); 
    head->next->next->next = newLinkNode(4);

    printList(head);
	deleteMiddle(&head);
	printList(head);

	printf("---------\n");

	Link_Node* head2 = newLinkNode(1); 
    head2->next = newLinkNode(2); 
    head2->next->next = newLinkNode(3); 
    head2->next->next->next = newLinkNode(4);
    head2->next->next->next->next = newLinkNode(5);

    printList(head2);
	deleteMiddle(&head2);
	printList(head2);

	printf("---------\n");

	Link_Node* head3 = newLinkNode(1); 

	printList(head3);
	deleteMiddle(&head3);
	printList(head3);
	  
  return 0; 
}