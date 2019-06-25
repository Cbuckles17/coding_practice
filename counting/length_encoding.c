#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

char* length_encoding(char *input, char *output)
{
	char cchar;
	int counter = 0;
	int ccount = 0;

	//we want to loop until strlen so we capture the last char and see that it DNE '\0' and add its data to the str
	for(counter = 0; counter <= strlen(input); counter++)
	{
		if(input[counter] != cchar)
		{
			if(counter != 0)
			{
				sprintf(output + strlen(output), "%c%d", cchar, ccount);
			}

			cchar = input[counter];
			ccount = 1;
		}
		else
		{
			ccount++;
		}
	}

	return output;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/length_encoding length_encoding.c
//./build/length_encoding

int main()
{
	//w4a3d1e1x6
	char test1[] = "wwwwaaadexxxxxx";
	char outputtest1[30] = {0};

	//w15
	char test2[] = "wwwwwwwwwwwwwww";
	char outputtest2[30] = {0};

	//g1e2k1s1f1o1r1g1e2k1s1
	char test3[] = "geeksforgeeks";
	char outputtest3[26] = {0};

	printf("input: %s output: %s\n", test1, length_encoding(test1, outputtest1));
	printf("input: %s output: %s\n", test2, length_encoding(test2, outputtest2));
	printf("input: %s output: %s\n", test3, length_encoding(test3, outputtest3));

	return 0;
}