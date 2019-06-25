#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void maxcontiguoussequence(int *input, int length)
{
	int sum = INT_MIN;
	int csum = 0;
	int counter = 0;

	for(counter = 0; counter < length; counter++)
	{
		csum+=input[counter];

		//this is in its owns if statement so we can check if a negative number is the actual max
		if(csum > sum)
		{
			sum = csum;
		}

		//if we have positive numbers then we do not want a negative csum
		if(csum < 0)
		{
			csum = 0;
		}
	}

	printf("Max Sum is: %d\n", sum);
	return;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/max_contiguous_sequence max_contiguous_sequence.c
//./build/max_contiguous_sequence

int main()
{
	int test1[] = {-8, 3, -2, 4, -10};
	int test2[] = {-10, -5, -2, -8};

	maxcontiguoussequence(test1, 5);
	maxcontiguoussequence(test2, 4);

	return 0;
}