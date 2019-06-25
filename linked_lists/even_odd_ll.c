#include <stdio.h> 
#include <stdlib.h> 
#include "lib/link_node.h"

void evenodd_ll(Link_Node **listref)
{
	if(*listref == NULL || (*listref)->next == NULL)
	{
		return;
	}

	Link_Node *even_head = *listref;
	Link_Node *even_runner = *listref;
	Link_Node *even_slow_runner = NULL;
	Link_Node *odd_head = NULL;
	Link_Node *odd_runner = NULL;

	while(even_runner != NULL)
	{	
		//the data is odd
		if(even_runner->data % 2 == 1)
		{
			//first odd number
			if(odd_head == NULL)
			{
				odd_head = even_runner;
				odd_runner = odd_head;
			}
			//not the first odd so just set it to it's next
			else
			{
				odd_runner->next = even_runner;
				odd_runner = odd_runner->next;
			}

			//we are at the front of the even list
			if(even_slow_runner == NULL)
			{
				//move the head pointer since we are losing our head
				even_head = even_head->next;
				//move the even runner to the new head
				//slow runner is still NULL since we are still at the front of the list
				even_runner = even_head;
			}
			//remove the middle man if not at the front
			else
			{
				even_slow_runner->next = even_runner->next;
				//move the even_runner
				//leave the slow runner since it is still the last node
				even_runner = even_runner->next;
			}

			//sever the old connection
			odd_runner->next = NULL;
		}
		//even
		else
		{
			//move the even_runner and save off it's last
			even_slow_runner = even_runner;
			even_runner = even_runner->next;
		}
	}

	//if this is NULL at the end that means we had all odds
	if(even_slow_runner == NULL)
	{
		*listref = odd_head;
	}
	//we had evens. odd_head could be empty but that's fine
	else
	{
		even_slow_runner->next = odd_head;
		*listref = even_head;
	}

	return;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/even_odd_ll even_odd_ll.c lib/link_node.c
//./build/even_odd_ll

int main()
{
	Link_Node* head = newLinkNode(1); 
    head->next = newLinkNode(2); 
    head->next->next = newLinkNode(3); 
    head->next->next->next = newLinkNode(4);
    head->next->next->next->next = newLinkNode(5);

    printList(head);
    evenodd_ll(&head);
    printList(head);
    printf("--------\n");

	Link_Node* head2 = newLinkNode(7); 
    head2->next = newLinkNode(5); 
    head2->next->next = newLinkNode(3); 
    head2->next->next->next = newLinkNode(4);
    head2->next->next->next->next = newLinkNode(5);

    printList(head2);
    evenodd_ll(&head2);
    printList(head2);
    printf("--------\n");

    Link_Node* head3 = newLinkNode(7); 
    head3->next = newLinkNode(5); 
    head3->next->next = newLinkNode(3); 
    head3->next->next->next = newLinkNode(1);
    head3->next->next->next->next = newLinkNode(9);

    printList(head3);
    evenodd_ll(&head3);
    printList(head3);
    printf("--------\n");

    Link_Node* head4 = newLinkNode(8); 
    head4->next = newLinkNode(2); 
    head4->next->next = newLinkNode(6); 
    head4->next->next->next = newLinkNode(4);
    head4->next->next->next->next = newLinkNode(0);

    printList(head4);
    evenodd_ll(&head4);
    printList(head4);

	return 0;
}