#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>

int runisdigit(char *subip) 
{ 
    while(*subip != '\0')
    {
    	if(!isdigit(*subip))
    	{
    		//error
    		//printf("invalid digit: %c\n", *subip);
    		return 0;
    	}

    	subip++;
    }

    //pass
    return 1;
} 

void validateip(char *ip)
{
	int counter = 0;
	int checksub = 0;
	char *token = NULL;

	if(ip == NULL)
	{
		printf("Empty IP Given\n");
		return;
	}

	token = strtok(ip, ".");

	//loop until no more . are found
	while(token != NULL)
	{
		//printf("%s\n", token);
		//end the loop if we seen 4 segments already
		if(counter >= 4)
		{
			printf("Invalid ip. Too many sub ips\n");
			return;
		}
		else if(runisdigit(token) == 0)
		{
			printf("Invalid ip. Sub contains non digit chars\n");
			return;
		}

		counter++;
		checksub = atoi(token);

		//make sure the sub is between 0-255
		if(checksub < 0 || checksub > 255)
		{
			printf("Invalid ip. Sub not between 0-255\n");
			return;
		}

		token = strtok(NULL, ".");		
	}

	if(counter != 4)
	{
		printf("Invalid ip. Too little sub ips\n");
		return;
	}

	printf("valid ip\n");
	return;
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/validate_ip validate_ip.c
//./build/validate_ip

int main()
{
	char test1[] = "192.168.1.1.2";
	char ip1[] = "128.0.0."; 
    char ip2[] = "125.16.100.1"; 
    char ip3[] = "125.512.100.1"; 
    char ip4[] = "125.abc.100.abc";

	validateip(test1);
	validateip(ip1);
	validateip(ip2);
	validateip(ip3);
	validateip(ip4);

	return 0;
}