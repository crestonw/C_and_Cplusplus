#include <stdio.h>
#include <stdlib.h>
#include <image.h>
#ifndef SOURCE
#define SOURCE

class Source
{
	private:
		Image img;
	
	public:
		virtual void Execute(void) = 0;
		
		Image * GetOutput();
};

#endif
