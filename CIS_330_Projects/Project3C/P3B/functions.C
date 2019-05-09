#include <image.h>
#include <functions.h>
#include <stdlib.h>
#include <stdio.h>

void ReadImage(char *filename, Image &output)
{
	// Initialize variables
	char magicNum[128];
	int width, height, maxval;
	FILE *f_in = fopen(filename, "r");
	
	// Read the header of the file into our variables
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);

	// Reset the size of the output image size
	output.ResetSize(output.width, output.height);
	
	// Set and initialize output image variables
	output.width = width;
	output.height = height;
	output.pixels = (Pixel *) malloc(sizeof(Pixel) * width * height);
	
	fread(output.pixels, sizeof(Pixel)*width*height, 1, f_in);
	
	fclose(f_in); 
}

void WriteImage(char *filename, Image &img)
{
	FILE *f_out = fopen(filename, "w");
	
	fprintf(f_out, "%s\n%d %d\n%d\n", "P6", img.width, img.height, 255);
	
	fwrite(img.pixels, sizeof(Pixel), (img.width * img.height), f_out);

	fclose(f_out);
}

void HalfSize(Image &input, Image &output)
{
	output.width = input.width/2;
	output.height = input.height/2;
	output.pixels = (Pixel *) malloc(sizeof(Pixel) * output.width * output.height);

	for (int i = 0; i < (output.height); i++)
	{
			for ( int j = 0; j < (output.width); j++)
		{	
			output.pixels[i*output.width+j] = input.pixels[(i*2) * input.width + (j*2)];
		}
	}	
}

void LeftRightCombine(Image &leftInput, Image &rightInput, Image &output)
{
	output.width = leftInput.width + rightInput.width;
	output.height = leftInput.height;
	output.pixels = (Pixel *) malloc(sizeof(Pixel) * output.width * output.height);

	for (int i = 0; i < (output.height); i++)
	{
		for (int j = 0; j < (leftInput.width); j++)
		{	
			output.pixels[i*output.width+j] = leftInput.pixels[i*leftInput.width+j];
		}

		for (int k = 0; k < (rightInput.width); k++)
		{
			output.pixels[i*output.width+(leftInput.width + k)] = rightInput.pixels[i*rightInput.width+k];
		}
	}
}

void TopBottomCombine(Image &topInput, Image &bottomInput, Image &output)
{
	output.width = topInput.width;
	output.height = topInput.height + bottomInput.height;
	output.pixels = (Pixel *) malloc(sizeof(Pixel) * output.height * output.width);

	for (int i = 0; i < (output.height * output.width); i++)
	{
		if (i < (topInput.width * topInput.height))
		{
			output.pixels[i] = topInput.pixels[i];
		}

		else 
		{	
			output.pixels[i] = bottomInput.pixels[i - (topInput.width*topInput.height)];
		}
	}
}

void Blend(Image &input1, Image &input2, double factor, Image &output)
{
	output.width = input1.width;
	output.height = input1.height;
	output.pixels = (Pixel *) malloc(sizeof(Pixel) * output.width * output.height);

	for (int i = 0; i < (output.height*output.width); i++)
	{
		output.pixels[i].r = factor * input1.pixels[i].r + (1-factor) * input2.pixels[i].r;
		output.pixels[i].g = factor * input1.pixels[i].g + (1-factor) * input2.pixels[i].g;
		output.pixels[i].b = factor * input1.pixels[i].b + (1-factor) * input2.pixels[i].b;
	}
}
