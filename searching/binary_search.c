#include <stdio.h> 
#include <stdlib.h> 

int bs(int *array, int left, int right, int num)
{
	if(left <= right) //checking we aren't at the end of a search
	{
		int mid = (left + right) / 2;

		if(array[mid] == num)
		{
			return mid;
		}
		else if(array[mid] > num) //go left
		{
			return bs(array, left, mid - 1, num);
		}
		else // go right
		{
			return bs(array, mid + 1, right, num);
		}
	}

	return -1;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/binary_search binary_search.c
//./build/binary_search

int main() 
{ 
   int arr1[] = {1, 2, 3, 5, 6, 7, 8, 9, 10}; 
   int size1 = sizeof(arr1)/sizeof(arr1[0]); 
   int num1 = 2; 
   int num2 = 6;
   int num3 = 10;

   printf("index of %d: %d\n", num1, bs(arr1, 0, size1 - 1, num1));
   printf("index of %d: %d\n", num2, bs(arr1, 0, size1 - 1, num2));
   printf("index of %d: %d\n", num3, bs(arr1, 0, size1 - 1, num3));

   return 0; 
} 