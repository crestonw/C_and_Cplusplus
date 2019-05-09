#include <stdio.h>
#include <stdlib.h>
#include <PNMwriter.h>

/*
The method write that takes a filename and creates a file with given filename.
Then writes the contents of an Image object into that file.
*/
void
PNMwriter::Write(char *filename)
{
	FILE *f_out = fopen(filename, "w");
	Image *img = new Image(this->GetImg1());

        fprintf(f_out, "%s\n%d %d\n%d\n", "P6", img->GetWidth(), img->GetHeight(), 255);

        fwrite(img->GetPixels(), sizeof(Pixel), (img->GetWidth() * img->GetHeight()), f_out);

        fclose(f_out);
}
