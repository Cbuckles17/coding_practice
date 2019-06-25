#include <stdio.h> 
#include <stdlib.h> 

void equalsumsatindex(int *input, int length)
{
	int sumleft = 0;
	int sumright = 0;
	int counter = 0;

	if(input == NULL || length == 0)
	{
		return;
	}

	//add up the list 
	for(counter = 0; counter < length; counter++)
	{
		sumright+=input[counter];
	}

	for(counter = 0; counter < length; counter++)
	{
		//remove the current index value from the sum 
		//since we are comparing to the right of that index
		sumright-=input[counter];

		if(sumleft == sumright)
		{
			printf("Left and Right Sums: %d %d Match at Index: %d\n", sumleft, sumright, counter);
		}

		//increment this for the next comparision
		sumleft+=input[counter];
	}

	return;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/equal_sums_at_index equal_sums_at_index.c
//./build/equal_sums_at_index

int main()
{
	int test1[] = {-5, 5, -5};
	int test2[] = {1, 2, 3};
	int test3[] = {2, 3, 5, 1, 4};
	int test4[] = {0};

	equalsumsatindex(test1, 3);
	printf("-----\n");
	equalsumsatindex(test2, 3);
	printf("-----\n");
	equalsumsatindex(test3, 5);
	printf("-----\n");
	equalsumsatindex(test4, 1);

	return 0;
}