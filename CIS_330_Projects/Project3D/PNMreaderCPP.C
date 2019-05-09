#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <PNMreaderCPP.h>

PNMreaderCPP::PNMreaderCPP(char *filename)
{
	this->filename = filename;
}

void
PNMreaderCPP::Execute()
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
