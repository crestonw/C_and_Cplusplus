#include <stdio.h>
#include <stdlib.h>
#include <source.h>

/*
The class PNMreader that is a Source. This class has a filename data member
with getters and setter methods. The method also implements its own Execute
method.
*/
class PNMreader : public Source
{
	private:
		char *filename;
	public:
		PNMreader(char *filename);
		virtual void Execute();

		char * GetFilename() { return filename; };
		void SetFilename(char *file) { filename = file; };
		virtual const char* SourceName() { return "PNMreader"; };
};