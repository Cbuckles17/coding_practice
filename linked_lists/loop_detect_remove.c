#include <stdio.h> 
#include <stdlib.h> 
#include "lib/link_node.h"

void remove_loop(Link_Node *runnerstart, Link_Node *runnerloop)
{
	Link_Node *rem = NULL;

	//go one by one until slart and loop detected spot collide
	//keep a slower runner to be able to delete the link
	while(runnerstart != runnerloop)
	{
		rem = runnerloop;
		runnerstart = runnerstart->next;
		runnerloop = runnerloop->next;
	}

	rem->next = NULL;
	return;
}

void loop_detect(Link_Node *input)
{
	Link_Node *slow = input;
	Link_Node *fast = input;

	while(slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
		{
			printf("Loop found\n");
			slow = input;
			remove_loop(slow, fast);
			
			return;
		}
	}

	return;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/loop_detect_remove loop_detect_remove.c lib/link_node.c
//./build/loop_detect_remove

int main()
{
	Link_Node *head = newLinkNode(50); 
    head->next = newLinkNode(20); 
    head->next->next = newLinkNode(15); 
    head->next->next->next = newLinkNode(4); 
    head->next->next->next->next = newLinkNode(10);
    //create the loop
    head->next->next->next->next->next = head->next->next;

    loop_detect(head);
    printList(head);

    return 0;
}