#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void minimalgrouping(char *input)
{
	int length = strlen(input);
	int counter1 = length - 1;
	int csum = 0;
	int clast = INT_MIN;
	int alphabet[128] = {};

	if(input == NULL || length == 0)
	{
		printf("Empty or NULL String Given\n");
		return;
	}
	else
	{
		printf("Min Grouping: [");
	}

	//find the last occurence of each char
	for(counter1 = length - 1; counter1 >= 0; counter1--)
	{
		if(alphabet[input[counter1]] == 0)
		{
			alphabet[input[counter1]] = counter1;
			//printf("last %c: %d\n", input[counter1], alphabet[input[counter1]]);
		}
	}

	for(counter1 = 0; counter1 < length; counter1++)
	{
		//if the current last is less than the last of the current char then set it
		if(clast <= alphabet[input[counter1]])
		{
			clast = alphabet[input[counter1]];
		}

		csum++;

		//if your current last is equal to where you are
		//this if statement is just for pretty printing
		//this basically if checking if you aren't at the end of the string aka add a comma
		if(clast == counter1 && counter1 + 1 != length)
		{
			printf("%d,", csum);
			csum = 0;
		}
		else if(clast == counter1)
		{
			printf("%d", csum);
			csum = 0;
		}
	}

	printf("]\n");

	return;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/minimal_grouping_string minimal_grouping_string.c
//./build/minimal_grouping_string

int main()
{
	char test1[] = "abc";
	char test2[] = "abca";
	char test3[] = "abacbadehdelmnl";
	char test4[] = "";

	minimalgrouping(test1);
	printf("-------\n");
	minimalgrouping(test2);
	printf("-------\n");
	minimalgrouping(test3);
	printf("-------\n");
	minimalgrouping(test4);

	return 0;
}