#include <stdio.h>
#include <stdlib.h>
#include <image.h>
#include <logging.h>
#ifndef SINK_330
#define SINK_330

/*
The class Sink that has two pointers to Image objects for data members.
It has a default constructor and getters and setters for the data members.
*/
class Sink
{
	protected:
		Image *input1;
		Image *input2;
		virtual const char *SinkName() = 0;

	public:
		Sink();
		void SetInput(Image *image);
		void SetInput2(Image *image);

		Image * GetInput1() { return input1; };
		Image * GetInput2() { return input2; };

};

#endif
