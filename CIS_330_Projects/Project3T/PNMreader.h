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
		const char *filename;
	public:
		PNMreader(const char *filename);
		virtual void Execute();

		const char * GetFilename() const { return filename; };
		void SetFilename(const char *file) { filename = file; };
		virtual const char* SourceName() { return "PNMreader"; };
};
