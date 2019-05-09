// Author: Creston Wilson
// References: Lab3.c code and geeksforgeeks.org

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a struct called IntArray
struct IntArray 
{

	int length;
	int *dataPtr;

};

struct IntArray *mallocIntArray(int length)
{
// The struct of type IntArray allocates memory, initializes variables, and returns an instance of the struct.

	struct IntArray *array = NULL;
	array = (struct IntArray *) malloc(sizeof(struct IntArray));
	array->length = length;
	array->dataPtr = (int *) malloc(sizeof(int) * length);

	if(array->dataPtr == NULL) 
	{
		fprintf(stderr, "Malloc failed!\n");
		exit(2);
	}
	for (int i = 0; i < length-1; ++i)
	{
		array->dataPtr[i] = 0;	
	}
	return array; 	
}

void freeIntArray(struct IntArray **arrayPtr) 
{
    // free up all the memory that was being used by the IntArray.
    
	if((arrayPtr != NULL) && ((*arrayPtr) != NULL))
	{
		for (int i = 0; i < (*arrayPtr)->length; ++i)
		{
			(*arrayPtr)->dataPtr[i] = 0;
		}
		free((*arrayPtr)->dataPtr);
		(*arrayPtr)->dataPtr = 0;
		(*arrayPtr)->length = 0;
		free((*arrayPtr));
		(*arrayPtr) = 0;
	}
	else
	{
		fprintf(stderr, "Error in freeIntArray, bad pointer found.\n");
		exit(-1);
	}
}

void readIntArray(struct IntArray *array)
// Prompts and reads int from the user and inputs into an IntArray.
{
    char str[256];
    long integer;
    
    // Iterate through the array and fill with user input.
	for (int i = 0; i < (array->length); i++)
	{
        printf("Enter int: ");
        scanf("%s", str);
        integer = strtol(str, NULL, 10);
        printf("\n");
		array->dataPtr[i] = (int) integer;
	}
}

void swap(int *xp, int *yp) 
// Uses pointers to swap to integers.
{
  int t0 = *xp;
  int t1 = *yp;
  *xp = t1;
  *yp = t0;
}

void sortIntArray(struct IntArray *array)
// Uses the bubblesort algorithm and the swap function to sort an IntArray.
{
	int i, j;
	for (i = 0; i < ((array->length)-1); i++)      
	{
    	// Last i elements are already in place   
        for (j = 0; j < ((array->length)-i-1); j++) 
        {
        	if (array->dataPtr[j] > array->dataPtr[j+1])
           	{	
           		swap((&(array->dataPtr[j])), &(array->dataPtr[j+1]));
        	}
        }
    }
}

void printIntArray(struct IntArray *array)
{
    // prints the opening bracket
    printf("[");
    
    // iterate through the array and print each element
    for (int i = 0; (i < (array->length)); i++) {
        printf("%d ", array->dataPtr[i]);
    }
    
    // print the closing bracket
    printf("]\n");
}

int main()
// Main method
{
    // Read an Integer into length
    char str[256];
    long length;

    printf("Enter length: ");
    scanf("%s", str);
    length = strtol(str, NULL, 10);
    printf("\n");
    
    // Create an IntArray of size length
    struct IntArray array = *mallocIntArray(length);
    
    // Read length number of integers
    readIntArray(&array);
    
    // Sort the IntArray
    sortIntArray(&array);
    
    // Print the IntArray
    printIntArray(&array);
    
	return 0;
}
