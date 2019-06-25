#include <stdio.h> 
#include <stdlib.h>
#include "lib/link_node.h"

void combine_ll(Link_Node **newlist, Link_Node *oldlist)
{
	Link_Node *holder = NULL;
	Link_Node *newlistinc = NULL;

	//means that the new list is empty so just copy all the contents of the old list over
	if(*newlist == NULL)
	{
		*newlist = newLinkNode(oldlist->data);
		newlistinc = *newlist;
		oldlist = oldlist->down;

		while(oldlist != NULL)
		{
			//printf("Copying data: %d\n", oldlist->data);
			newlistinc->next = newLinkNode(oldlist->data);
			newlistinc = newlistinc->next;
			oldlist = oldlist->down;
		}

		return;
	}

	newlistinc = *newlist;

	//loop until we get to the end of either list
	while(oldlist != NULL && newlistinc->next != NULL)
	{	
		//if the oldlist data is in a range it can be inserted into the newlist
		if(newlistinc->data <= oldlist->data && newlistinc->next->data >= oldlist->data)
		{
			//insert the new node
			holder = newlistinc->next;
			newlistinc->next = newLinkNode(oldlist->data);
			newlistinc = newlistinc->next;
			newlistinc->next = holder;
			oldlist = oldlist->down;
		}
		else
		{
			newlistinc = newlistinc->next;
		}
	}

	//this means that the newlist ended before looping through the old list
	while(oldlist != NULL)
	{
		//printf("Copying data: %d\n", oldlist->data);

		newlistinc->next = newLinkNode(oldlist->data);
		newlistinc = newlistinc->next;
		oldlist = oldlist->down;
	}

	return;
}

void combine_ll_helper(Link_Node **newlist, Link_Node *oldlist)
{
	if(oldlist == NULL)
	{
		return;
	}

	//combine the lists
	combine_ll(newlist, oldlist);

	//loop to the next and combine
	combine_ll_helper(newlist, oldlist->next);
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/flatten_linked_list flatten_linked_list.c lib/link_node.c
//./build/flatten_linked_list

int main()
{
	Link_Node *root = NULL;
	Link_Node *returnlist = NULL; 
  
    /* 5 -> 10 -> 19 -> 20 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
    */
    pushNewDown(&root, 30);
    pushNewDown(&root, 8);
    pushNewDown(&root, 7);
    pushNewDown(&root, 5);

    //combine_ll(&returnlist, root);
  	
  	pushNewDown(&(root->next), 20);
  	pushNewDown(&(root->next), 10);

    //combine_ll(&returnlist, root->next);
  	
  	pushNewDown(&(root->next->next), 50);
  	pushNewDown(&(root->next->next), 22);
  	pushNewDown(&(root->next->next), 19);

    //combine_ll(&returnlist, root->next->next);
  	
  	pushNewDown(&(root->next->next->next), 45);
  	pushNewDown(&(root->next->next->next), 40);
  	pushNewDown(&(root->next->next->next), 35);
  	pushNewDown(&(root->next->next->next), 20);

    //combine_ll(&returnlist, root->next->next->next);

    combine_ll_helper(&returnlist, root);

    printList(returnlist);
}