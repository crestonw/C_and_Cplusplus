#include <stdio.h>
#include <stdlib.h>
#include <source.h>

class PNMreader : public Source
{		
	private:
		char *filename;
	public:
		PNMreader(char *filename);
		virtual void Execute();

		char * GetFilename() { return filename; };
		void SetFilename(char *file) { filename = file; };
};
