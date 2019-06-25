#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rem_dup_inplace(char *input)
{
	int old_pos = 0;
	int cur_pos = 0;
	char alphabet[128] = {0};

	printf("Before Remove Dups: %s\n", input);

	for(old_pos = 0; old_pos < strlen(input); old_pos++)
	{
		//printf("char: %c ascii: %d count: %d\n", input[old_pos], to_ascii, alphabet[(char)input[old_pos]]);

		if(alphabet[input[old_pos]] == 0)
		{
			alphabet[input[old_pos]]++;
			if(cur_pos != old_pos)
			{
				input[cur_pos] = input[old_pos];
			}

			cur_pos++;
		}

		//printf("Between Remove Dups: %s\n", input);
	}

	input[cur_pos] = '\0';
	printf("After Remove Dups: %s\n\n", input);
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/rem_dup_inplace rem_dup_inplace.c
//./build/rem_dup_inplace

int main() 
{ 
 	char test1[] = "testing";
 	char test2[] = "aaaaabbbbbca";
 	char test3[] = "help";
 	char test4[] = "ABBSDBJJKKSDasnbbbasbas";
 	char test5[] = "geeksforgeeks";
 	char test6[] = "$@@@1a";

	rem_dup_inplace(test1);
	rem_dup_inplace(test2);
	rem_dup_inplace(test3);
    rem_dup_inplace(test4);
    rem_dup_inplace(test5);
    rem_dup_inplace(test6);

  return 0; 
}