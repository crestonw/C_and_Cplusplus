#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
// Uses pointers to swap to integers.
{
  int t0 = *xp;
  int t1 = *yp;
  *xp = t1;
  *yp = t0;
}

void bubble(int array[], size_t size)
{
	int i = 0;
	int temp;
	int again = 1;
	int iter = size - 1;

	do {
		again = 0;
		i = 0;
		for(; i < iter; ++i)
			{
				if (array[i + 1] < array[i])
					{
						again = 1;
					        swap(&array[i], &array[i+1]);
					}
			}
		--iter;
	} while (again);
}

int main(void)
{
	int array[] = {5, 1, 4, 2, 8, 0, -11, 3, 8, 9};

	bubble(array, (sizeof array / sizeof (int)));
}
