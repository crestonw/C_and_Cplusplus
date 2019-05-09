#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <PNMreader.h>

// The Parameter Constructor for PNMreader.
PNMreader::PNMreader(char *filename)
{
	this->filename = filename;
}

/*
The Execute method for PNMreader. This method reads from a filename declared by
the constructor and puts the file contents in an Image object.
*/
void
PNMreader::Execute()
{
	// Initialize variables
	char magicNum[128];
        int width, height, maxval;
        FILE *f_in = fopen(this->filename, "r");

        // Read the header of the file into our variables
        fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	this->GetOutput()->SetWidth(width);
	this->GetOutput()->SetHeight(height);

	Pixel *p = (Pixel *) malloc(sizeof(Pixel) * width * height);

	fread(p, sizeof(Pixel)*width*height, 1, f_in);

	this->GetOutput()->SetPixels(p);

	fclose(f_in);
}
