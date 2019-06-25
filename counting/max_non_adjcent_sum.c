#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
#include <string.h>

int maxnonadjcentsum(int *array, int length)
{
	int counter = 2;
	int sum[length];
	memset(sum, INT_MIN, length);

	if(array == NULL || length == 0)
	{
		return INT_MIN;
	}
	else if(length == 1)
	{
		return array[0];
	}
	else if(length == 2)
	{
		//simulated max()
		if(array[0] >= array[1])
		{
			return array[0];
		}
		else
		{
			return array[1];
		}
	}
	//initialize sum[0] and sum[1]
	else
	{
		sum[0] = array[0];

		if(array[0] >= array[1])
		{
			sum[1] = array[0];
		}
		else
		{
			sum[1] = array[1];
		}
	}

	for(counter = 2; counter < length; counter++)
	{
		//find the max of nonadjcent sum + current spot vs adjcent sum
		//max(sum[counter - 2] + array[counter], sum[counter - 1])
		if((sum[counter - 2] + array[counter]) >= sum[counter - 1])
		{
			sum[counter] = sum[counter - 2] + array[counter];
		}
		else
		{
			sum[counter] = sum[counter - 1];
		}
	}

	//go back 1 since we incremented 1 extra above in the for loop
	return sum[counter - 1];
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/max_non_adjcent_sum max_non_adjcent_sum.c
//./build/max_non_adjcent_sum

int main()
{
	int test1[] = {6, 7, 1, 3, 8, 2, 4};
	int test2[] = {5, 3, 4, 11, 2};
	int test3[] = {};
	int test4[] = {90, 2};

	printf("Max Nonadjcent Sum1 = %d\n", maxnonadjcentsum(test1, 7));
	printf("Max Nonadjcent Sum2 = %d\n", maxnonadjcentsum(test2, 5));
	printf("Max Nonadjcent Sum3 = %d\n", maxnonadjcentsum(test3, 0));
	printf("Max Nonadjcent Sum4 = %d\n", maxnonadjcentsum(test4, 2));
}