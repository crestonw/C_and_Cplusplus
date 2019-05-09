#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	
	FILE *input;
	FILE *output;
	unsigned int *buffer;
	
	if (argc != 3)
	{
		printf("Usage: %s <file1> <file2>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	input = fopen(argv[1], "r");
	output = fopen(argv[2], "w");
	buffer = malloc(sizeof(int)*5);
	
	fseek(input, 0, SEEK_SET);
	fread(buffer, sizeof(int), 5, input);
	fprintf(output, "%d\n", buffer[0]);
	fprintf(output, "%d\n", buffer[1]);
	fprintf(output, "%d\n", buffer[2]);
	fprintf(output, "%d\n", buffer[3]);
	fprintf(output, "%d\n", buffer[4]);

	fseek(input, 20, SEEK_CUR);
	fread(buffer, sizeof(int), 5, input);
	fprintf(output, "%d\n", buffer[0]);
	fprintf(output, "%d\n", buffer[1]);
	fprintf(output, "%d\n", buffer[2]);
	fprintf(output, "%d\n", buffer[3]);
	fprintf(output, "%d\n", buffer[4]);
	
	fseek(input, 20, SEEK_CUR);
	fread(buffer, sizeof(int), 5, input);
	fprintf(output, "%d\n", buffer[0]);
	fprintf(output, "%d\n", buffer[1]);
	fprintf(output, "%d\n", buffer[2]);
	fprintf(output, "%d\n", buffer[3]);
	fprintf(output, "%d\n", buffer[4]);
	
	fseek(input, 20, SEEK_CUR);
	fread(buffer, sizeof(int), 5, input);
	fprintf(output, "%d\n", buffer[0]);
	fprintf(output, "%d\n", buffer[1]);
	fprintf(output, "%d\n", buffer[2]);
	fprintf(output, "%d\n", buffer[3]);
	fprintf(output, "%d\n", buffer[4]);
	
	fseek(input, 20, SEEK_CUR);
	fread(buffer, sizeof(int), 5, input);
	fprintf(output, "%d\n", buffer[0]);
	fprintf(output, "%d\n", buffer[1]);
	fprintf(output, "%d\n", buffer[2]);
	fprintf(output, "%d\n", buffer[3]);
	fprintf(output, "%d\n", buffer[4]);

	fclose(input);
	fclose(output);
	return 0;
}
