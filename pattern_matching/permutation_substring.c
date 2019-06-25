#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int compare_dicts(int dict1[], int dict2[], int length)
{
	int counter1 = 0;

	for(counter1 = 0; counter1 < length; counter1++)
	{
		if(dict1[counter1] != dict2[counter1])
		{
			return 0;
		}
	}

	return 1;
}

void perm_substring(char *input, char *pattern)
{
	int inputlen = strlen(input);
	int patternlen = strlen(pattern);
	int inputdict[128] = {0};
	int patterndict[128] = {0};
	int counter1 = 0;

	//find all the counts for the length of pattern at the beginning
	for(counter1 = 0; counter1 < patternlen; counter1++)
	{
		inputdict[input[counter1]]++;
		patterndict[pattern[counter1]]++;
	}

	// if(compare_dicts(inputdict, patterndict, 128) == 1)
	// {
	// 	printf("Found Matching Perm Substring Starting at Index: 0\n");
	// }

	//memcmp does the same thing as the compare_dicts function
	if(memcmp(inputdict, patterndict, sizeof(inputdict)) == 0)
	{
		printf("Found Matching Perm Substring Starting at Index: 0\n");
	}

	//now loop through the rest of the input and comparing the dict at each index
	for(counter1 = patternlen; counter1 < inputlen; counter1++)
	{
		inputdict[input[counter1]]++;
		inputdict[input[counter1 - patternlen]]--;

		// if(compare_dicts(inputdict, patterndict, 128) == 1)
		// {
		// 	printf("Found Matching Perm Substring Starting at Index: %d\n", counter1 - patternlen + 1);
		// }

		if(memcmp(inputdict, patterndict, sizeof(inputdict)) == 0)
		{
			printf("Found Matching Perm Substring Starting at Index: %d\n", counter1 - patternlen + 1);
		}
	}

	return;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/permutation_substring permutation_substring.c
//./build/permutation_substring

int main()
{
	char input1[] = "BACDGABCDA";
	char pattern1[] = "ABCD";

	printf("Input: %s Pattern: %s\n", input1, pattern1);
	perm_substring(input1, pattern1);
	printf("-------\n");

	char input2[] = "AAABABAA";
	char pattern2[] = "AABA";

	printf("Input: %s Pattern: %s\n", input2, pattern2);
	perm_substring(input2, pattern2);

	return 0;
}