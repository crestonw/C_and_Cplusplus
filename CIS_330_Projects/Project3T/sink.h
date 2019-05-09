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
		const Image *input1;
		const Image *input2;
		virtual const char *SinkName() = 0;

	public:
		Sink();
		void SetInput(Image *image);
		void SetInput2(Image *image);

		const Image * GetInput1() const { return input1; };
		const Image * GetInput2() const { return input2; };

};

#endif
