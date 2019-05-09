#include <stdio.h>
#include <stdlib.h>
#include <sink.h>

class PNMwriterCPP : public Sink
{
	public:
		PNMwriterCPP(void);
		void Write(char *filename);
};
