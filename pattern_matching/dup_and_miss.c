#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

void dup_miss(int *input, int input_len)
{
	int icounter[input_len];
	memset(icounter, 0, input_len * sizeof(int));
	int counter = 0;
	int missing = 0;
	int dup = 0;

	//find dup aka a 1
	for(counter = 0; counter < input_len; counter++)
	{
		if(icounter[input[counter] - 1] == 0)
		{
			icounter[input[counter] - 1]++;
		}
		else
		{
			dup = input[counter];
		}
	}

	//find missing aka a 0
	for(counter = 0; counter < input_len; counter++)
	{
		if(icounter[counter] == 0)
		{
			missing = counter + 1;
			break;
		}
	}

	if(dup != 0)
	{
		printf("missing: %d dup: %d\n", missing, dup);
	}
	else
	{
		printf("Array is fine\n");
	}

	return;
}

//this uses the indexes to represent if the value has been seen
//it flips the sign of the value in the index to show whether it's been seen
//positive means not visited
//negative means visited
void printTwoElements(int *arr, int arr_len) 
{ 
    int i = 0; 
    printf("The repeating element is"); 
  
    for (i = 0; i < arr_len; i++) { 
    	//if the index is positive it means we haven't visited it before
        if (arr[abs(arr[i]) - 1] > 0) 
        {
            //flip the sign of the index to negative
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; 
        }
        else
        {
            //we hit a negative index so we've been here before
            printf(" %d ", abs(arr[i])); 
        }
    } 
  
    printf(" and the missing element is "); 
    for (i = 0; i < arr_len; i++) 
    { 
        //all indexes have been visited that exist and now they are negative
        //so find the only positive one and that is the missing
        if (arr[i] > 0) 
        {
            printf("%d\n\n", i + 1); 
        }
    } 
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/dup_and_miss dup_and_miss.c
//./build/dup_and_miss

int main()
{
	int arr[] = {7, 3, 4, 5, 5, 6, 2};
	dup_miss(arr, sizeof(arr)/sizeof(arr[0]));
	printTwoElements(arr, sizeof(arr)/sizeof(arr[0]));

	int arr2[] = {1, 3, 4, 5, 5, 6, 2};
	dup_miss(arr2, sizeof(arr2)/sizeof(arr2[0]));
	printTwoElements(arr2, sizeof(arr2)/sizeof(arr2[0]));

	return 0;
}