#include <stdio.h>
#include <stdlib.h>
#include <source.h>

class PNMreaderCPP : public Source
{		
	private:
		char *filename;
	public:
		PNMreaderCPP(char *filename);
		virtual void Execute();

		char * GetFilename() { return filename; };
		void SetFilename(char *file) { filename = file; };
};
