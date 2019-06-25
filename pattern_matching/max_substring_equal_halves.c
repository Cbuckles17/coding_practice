#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int longestsubequalhalves_revise(char *input)
{
	int length = strlen(input);
	int max = 0;
	int counter1 = 0;
	int left = 0;
	int right = 0;
	int csum = 0;
	
	//this will loop through all the possible mid points
	for(counter1 = 0; counter1 < length - 1; counter1++)
	{
		left = counter1;
		right = counter1 + 1;
		csum = 0;

		//loop until we go out of bounds
		while(left >= 0 && right < length)
		{	
			//convert char to digit aka remove the 0 from char->ascii value
			csum+=input[left]-'0';
			csum-=input[right]-'0';

			//if sum is 0 and the length is greater than the current max
			if(csum == 0 && right-left+1 > max)
			{
				max = right-left+1;
				printf("New Max Length: %d\n", max);
			}

			//expand
			left--;
			right++;
		}
	}

	return max;
}

int longestsubequalhalves(char *input)
{
	int length = strlen(input);
	int counter1 = 1;
	int counter2 = 0;
	int counter3 = 0;
	int csum = 0;
	int max = 0;

	if(input == NULL)
	{
		return max;
	}

	for(counter1 = 1; counter1 <= length/2; counter1++)
	{
		//printf("\nChecking for length %d\n\n", counter1 * 2);

		for(counter2 = 0; counter2 < length && (counter2 + (counter1 * 2) - 1) < length; counter2++)
		{
			//if((counter2 + (counter1 * 2) - 1) < length
			csum = 0;

			//printf("Checking from index %d\n", counter2);

			for(counter3 = 0; counter3 < counter1 * 2; counter3++)
			{
				if(counter3 < counter1) //left half
				{
					csum+=input[counter2 + counter3]-'0';
					//printf("Left Half Sum Added: %d\n", input[counter2 + counter3]-'0');
				}
				else
				{
					csum-=input[counter2 + counter3]-'0';
					//printf("Right Half Sum Subtracted: %d\n", input[counter2 + counter3]-'0');
				}
			}

			//printf("Sum: %d\n", csum);

			if(csum == 0 && counter1 * 2 > max)
			{
				max = counter1 * 2;
				printf("New Max Length: %d\n", max);
			}

			//printf("\n");
		}
	}

	return max;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/max_substring_equal_halves max_substring_equal_halves.c
//./build/max_substring_equal_halves

int main()
{
	char str[] = "1538023";
	char str2[] = "123123"; 
	char str3[] = "123321"; 

	//printf("\nMax Substring Equal Halves: %d\n-----\n", longestsubequalhalves(str));
	printf("\nMax Substring Equal Halves: %d\n-----\n", longestsubequalhalves_revise(str));

	//printf("\nMax Substring Equal Halves: %d\n-----\n", longestsubequalhalves(str2));
	printf("\nMax Substring Equal Halves: %d\n-----\n", longestsubequalhalves_revise(str2));

	//printf("\nMax Substring Equal Halves: %d\n-----\n", longestsubequalhalves(str3));
	printf("\nMax Substring Equal Halves: %d\n-----\n", longestsubequalhalves_revise(str3));
}