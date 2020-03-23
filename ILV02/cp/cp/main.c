//////////////////////////////////////////////////////////////////
//		  Salzburg University of Applied Sciences				//
//		Information Technology & Systems Management				//
//						SWE2-ILV/B								//
//////////////////////////////////////////////////////////////////
// date:			23.03.2020									//
//																//
//																//
// author:			Christoph Lenzbauer							//
// email:			clenzbauer.its-b2019@fh-salzburg.ac.at		//
//////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#pragma warning(disable:4996)

void copy(char* src, char* dst);

void main(int argc, char* argv[])
{
	setlocale(LC_ALL, "de_DE");

	char* src = argv[1];
	char* dst = argv[2];

	printf("Starting to copy files...\n");

	copy(src, dst);

	printf("Done!");

}

void copy(char* src, char* dst)
{
	FILE* srcFile = fopen(src, "r");
	FILE* dstFile = fopen(dst, "w");
	int size = 0;
	char* string = "";

	if (srcFile == NULL || dstFile == NULL)
	{
		printf("Error creating/opening File");
	}
	else
	{
		size = ftell(srcFile);

		string = malloc(size + 1);
		string[0] = '\0';

		char* buffer = malloc(size + 1); // "/0"

		while (fgets(buffer, size, srcFile) != NULL)
		{
			strcat(string, buffer);
		}

		fputs(string, dstFile);

		fclose(srcFile);
		fclose(dstFile);
	}
}