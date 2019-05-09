// Author: Creston Wilson
// Reference: CIS 314 Examples
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N 4
typedef int array_t[N][N];

void f_optimized(array_t a, int x, int y) 
{
	int i = 0;
	int j = 0;
	int mul = x * y;

	for (; i < N; ++i) 
	{
		int mult = i * mul;
		for (; j < N; ++j)
		{ 
			a[i][j] = mult + j;
		}
	}
}

int dim()
{
    return N;
}

void f(array_t a, int x, int y)
{
	for (int i = 0; i < dim(); ++i) 
	{
		for (int j = 0; j < dim(); ++j) 
		{ 
			a[i][j] = i * x * y + j;
		} 
	}
}

int main() 
{

	array_t a = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};

	struct timeval startO;
  	gettimeofday(&startO, NULL);

  	// Do this 100000 times to exaggerate the time taken.
	for (int i = 0; i < 100000; ++i) 
	{
		   f_optimized(a, i, i);   
  	}
  	

  	struct timeval currentO;
  	gettimeofday(&currentO, NULL);

  	long long elapsedO = (currentO.tv_sec - startO.tv_sec)*1000000LL + (currentO.tv_usec - startO.tv_usec);
  	printf("%f\n", elapsedO/1000.0);

  	struct timeval start;
  	gettimeofday(&start, NULL);

  	for (int i = 0; i < 100000; ++i)
  	{
	  	f(a, i, i);
  	}

  	struct timeval current;
  	gettimeofday(&current, NULL);

  	long long elapsed = (current.tv_sec - start.tv_sec)*1000000LL + (current.tv_usec - start.tv_usec);
  	printf("%f\n", elapsed/1000.0);
}