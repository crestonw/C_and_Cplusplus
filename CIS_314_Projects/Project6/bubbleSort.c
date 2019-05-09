#include <stdio.h>

void swap(int *xp, int *yp) 
// Uses pointers to swap to integers.
{
  int t0 = *xp;
  int t1 = *yp;
  *xp = t1;
  *yp = t0;
}

void sortIntArray(int* array, int count)
// Uses the bubblesort algorithm and the swap function to sort an IntArray.
{
	int i, j;
	for (i = 0; i < (count-1); i++)      
	{
    	// Last i elements are already in place   
        for (j = 0; j < (count-i-1); j++) 
        {
        	if (array[j] > array[j+1])
           	{	
           		swap((&(array[j])), &(array[j+1]));
        	}
        }
   }
}

void printArray(int* array)
{
	for (int i = 0; i < 10; i++)
	{
        	printf("%i", array[i]);
	}	
	printf("\n");
}

void main()
{

int array[10]= {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
sortIntArray(array, 10);
}

