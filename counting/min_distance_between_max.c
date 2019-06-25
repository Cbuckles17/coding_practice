#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void mindistancebetweenmax(int *input, int length)
{
	int min_dist = length;
	int cur_max = INT_MIN;
	int cur_dist = 0;
	int counter = 0;

	for(counter = 0; counter < length; counter++)
	{
		//found a new max so reset our counters
		if(input[counter] > cur_max)
		{
			cur_max = input[counter];
			cur_dist = 0;
			min_dist = length;
		}
		//found the same max so see if we have a min dist
		//then reset our current distance counter
		else if(input[counter] == cur_max)
		{
			//increment the distance for this node
			cur_dist++;

			//printf("Found another Max %d: dist %d and index %d\n", cur_max, cur_dist, counter);

			if(cur_dist < min_dist)
			{
				//printf("New Min Dist %d and index %d\n", cur_dist, counter);
				min_dist = cur_dist;
			}

			cur_dist = 0;
		}
		else
		{
			cur_dist++;
		}
	}

	printf("Min Distance Between Max: %d is %d\n", cur_max, min_dist);
	return;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/min_distance_between_max min_distance_between_max.c
//./build/min_distance_between_max

int main()
{
	int test1[] = {3, 5, 2, 3, 5, 3, 5};
	int test2[] = {1, 1, 1, 1, 1, 1};
	int test3[] = {5, 5, 6, 5, 5, 6};

	mindistancebetweenmax(test1, 7);
	printf("-------\n");
	mindistancebetweenmax(test2, 6);
	printf("-------\n");
	mindistancebetweenmax(test3, 6);

	return 0;
}