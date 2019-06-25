//Write a function that takes an array as a parameter. The array contains non-negative numbers.
//Every number in the array appears an even number of times, except for one number that appears an odd number of times.
//The function should return the number that appears an odd number of times.

#include <stdio.h>
#include <stdlib.h>

void oddcheck(int *array, int array_len)
{
    int counter = 0;
    
    for(counter = 0; counter < array_len; counter++)
    {
        if(array[abs(array[counter])] > 0)
        {
            array[array[counter]] = -(array[array[counter]]);
        }
        else if(array[abs(array[counter])] < 0)
        {
            array[array[counter]] = abs(array[array[counter]]);
        }
    }

    printf("hello\n");
    
    for(counter = 0; counter < array_len; counter++)
    {
        printf("Value: %d - index %d\n", abs(array[counter]) ,array[abs(array[counter])]);

        if(array[abs(array[counter])] < 0)
        {
            printf("Odd found: %d\n", abs(array[counter]));
            return;
        }
    }
    
    printf("no odds\n");
    return;
 }

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/medbridge_question medbridge_question.c
//./build/medbridgeinterview

int main() 
{ 
    int test1[] = {1,2,1};

    oddcheck(test1, 3);
 }