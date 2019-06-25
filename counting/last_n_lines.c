#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lastn(char *input, int n)
{
	char delim = '\n';
	//this goes to the last occurence of the delim
	char *currentpos = strrchr(input, delim);

	if(currentpos == NULL)
	{
		printf("There are not %d lines. Printing what is available.\n%s\n", n, input);
		return;
	}

	while(n > 0)
	{
		//while the current pos isn't a newline and we are still above the start of the file
		while(*currentpos != delim && currentpos > input)
		{
			currentpos--;
		}

		if(currentpos > input) //means we are at a delim
		{
			//we found a newline so minus the counter
			n--;
			//ignore the delim for next go round
			currentpos--;
		}
		else
		{
			printf("There are not enough lines. Printing what is available.\n%s\n", input);
			return;
		}
	}

	//move the currentpos 2 position foward since we decremented past the last delim. so move to go to delim then 1 more to go past it
	printf("There are enough lines at the end. Printing\n%s\n", 2+currentpos);
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/last_n_lines last_n_lines.c
//./build/last_n_lines

int main(void) 
{ 
    char str1[] = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9"
                 "\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17"
                 "\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25"; 
    char str2[] = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7"; 
    char str3[] = "\n"; 
    char str4[] = ""; 
  
    lastn(str1, 10); 
    printf("-----------------\n"); 
  
    lastn(str2, 10); 
    printf("-----------------\n"); 
  
    lastn(str3, 10); 
    printf("-----------------\n"); 
  
    lastn(str4, 10); 
    printf("-----------------\n"); 
  
    return 0; 
}