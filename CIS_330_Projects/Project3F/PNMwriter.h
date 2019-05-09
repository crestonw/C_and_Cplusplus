#include <stdio.h>
#include <stdlib.h>
#include <sink.h>

// The class PNMwriter that is a Sink. It has a default constructor and a Write method.
class PNMwriter : public Sink
{
	public:
		PNMwriter() {};
		void Write(char *filename);
		virtual const char*SinkName() { return "PNMwriter"; };
};
