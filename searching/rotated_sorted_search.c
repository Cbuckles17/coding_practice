#include <stdio.h> 
#include <stdlib.h> 

int search(int *array, int left, int right, int num)
{
	if(left <= right) //making sure we aren't at the end
	{
		int mid = (left + right) / 2;

		//printf("Current middle: %d\n", mid);

		if(num == array[mid])
		{
			return mid;
		}
		else if(array[left] < array[mid - 1])  //left side is a sorted side
		{
			//printf("Sorted Left Side - %d to %d\n", left, mid - 1);
			if(array[left] <= num && array[mid - 1] >= num) //num is in this range
			{
				//printf("Exists in Left Side\n\n");
				return search(array, left, mid - 1, num);
			}
			else //num has to be in this side then
			{
				//printf("Exists in Right Side\n\n");
				return search(array, mid + 1, right, num);
			}
		}
		else if(array[mid + 1] < array[right]) //righ side is a sorted side
		{
			//printf("Sorted Right Side - %d to %d\n", mid + 1, right);
			if(array[mid + 1] <= num && array[right] >= num) //num is in this range
			{
				//printf("Exists in Right Side\n\n");
				return search(array, mid + 1, right, num);
			}
			else //num has to be in this side then
			{
				//printf("Exists in Left Side\n\n");
				return search(array, left, mid - 1, num);
			}
		}
		else //neither side is sorted so that means we have dups and need to check both sides
		{
			//printf("Neither Side Sorted\n");

			int checkleft = search(array, left, mid - 1, num);
			if(checkleft >= 0)
			{
				return checkleft;
			}
			int checkright = search(array, mid + 1, right, num);
			if(checkright >= 0)
			{
				return checkright;
			}			
		}
	}

	return -1;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/rotated_sorted_search rotated_sorted_search.c
//./build/rotated_sorted_search

int main() 
{ 
   int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}; 
   int size1 = sizeof(arr1)/sizeof(arr1[0]); 
   int num = 2; 

   printf("index of %d: %d\n", num, search(arr1, 0, size1 - 1, num));

   int arr2[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
   int size2 = sizeof(arr2)/sizeof(arr2[0]); 
   int num2 = 6;

   printf("index of %d: %d\n", num2, search(arr2, 0, size2 - 1, num2));

   int arr3[] = {2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
   int size3 = sizeof(arr3)/sizeof(arr3[0]); 
   int num3 = 0;

   printf("index of %d: %d\n", num3, search(arr3, 0, size3 - 1, num3));

   return 0; 
} 