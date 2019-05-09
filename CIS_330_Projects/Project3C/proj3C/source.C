#include <source.h>
#include <stdio.h>
#include <stdlib.h>

Image*
Source::GetOutput()
{
	return &(this->img); 
}

