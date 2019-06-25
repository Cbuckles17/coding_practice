#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void substringreplace(char *input, char *sb1, char *sb2)
{
	char *output = NULL;
	int li = strlen(input);
	int lsb1 = strlen(sb1);
	int lsb2 = strlen(sb2);
	int lo = li - lsb1 + lsb2;
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;
	int begin = INT_MIN;
	int end = INT_MIN;

	//counter1 = input position
	//counter2 = sb1 position
	for(counter1 = 0; counter1 < li && counter2 < lsb1; counter1++)
	{
		//if we found a match to sb1
		if(input[counter1] == sb1[counter2])
		{
			//if this is the first char in sb1 string
			if(counter2 == 0)
			{
				begin = counter1;
				//printf("Sub found beginning at: %d\n", begin);
			}

			counter2++;

			//if we are at the end of the sb1 string
			if(counter2 == lsb1)
			{
				end = counter1;
				//printf("Sub found ending at: %d\n", end);
			}
		}
		//no matches so reset everything
		else
		{
			begin = INT_MIN;
			end = INT_MIN;
			counter2 = 0;
		}
	}

	//if we never found the end of sb1
	if(end == INT_MIN)
	{
		printf("Substring: %s not found in String: %s\n", sb1, input);
		return;
	}

	//printf("Begin: %d and End: %d of Substring1\n", begin, end);

	output = (char *)calloc(lo, sizeof(char));
	counter2 = 0;
	counter3 = 0;

	//counter1 = output position
	//counter2 = sb2 position
	//counter3 = input position
	//loop through the output string
	for(counter1 = 0; counter1 < lo; counter1++)
	{
		//if we are at the beginning or past the sb1 position in input
		//and we are not at the end of sb2 string
		if(counter1 >= begin && counter2 < lsb2)
		{
			//printf("add char: %c\n", sb2[counter2]);
			output[counter1] = sb2[counter2++];	
		}
		//if we reached the end of the sb2 or sb2 length is 0
		else if(counter1 >= begin && counter2 == lsb2)
		{
			//move the input position to the end of where we found sb1 in it
			counter3 = end + 1;
			//do this so we don't enter this if statment again
			counter2++;
			output[counter1] = input[counter3++];

		}
		//else just copy of the original input string
		else
		{
			output[counter1] = input[counter3++];
		}

		//printf("Substring: %s\n", output);
	}

	printf("Substring Replaced: %s\n", output);
	return;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/substring_replace substring_replace.c
//./build/substring_replace

int main()
{
	char input1[] = "testing123";
	char input11[] = "ing1";
	char input12[] = "s5";

	substringreplace(input1, input11, input12);

	char input2[] = "testing123";
	char input21[] = "sd";
	char input22[] = "s5";

	substringreplace(input2, input21, input22);

	char input3[] = "testing123";
	char input31[] = "1234";
	char input32[] = "s5";

	substringreplace(input3, input31, input32);

	char input4[] = "testing123";
	char input41[] = "testing123";
	char input42[] = "replaced987997979";

	substringreplace(input4, input41, input42);

	char input5[] = "testing123";
	char input51[] = "ing";
	char input52[] = "";

	substringreplace(input5, input51, input52);
	return 0;
}