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
#include <time.h>
#include <stdbool.h>
#include <string.h>

#pragma warning(disable:4996)

#define ANZ 50

int comp(const void* a, const void* b);
int compDesc(const void* a, const void* b);

void main(int argc, char* argv[]) {

	char* filename = argv[argc - 1];
	int count = 0;
	int i = 0;
	char c = 'x';
	char string[10];

	bool doSortAscending = true;

	for (int i = 0; i < argc - 1; i++) {

		if (strcmp(argv[i], "-h") == 0)
		{
			printf("\n\description of the options:");
			printf("\n\noption \t\t description");
			printf("\nx -h \t\t delivering a short description of the options");
			printf("\nx -a \t\t sorting ascending [default]");
			printf("\nx -d \t\t sorting descending");
		}

		else if (strcmp(argv[i], "-d") == 0)
		{
			doSortAscending = false;
		}
	}

	FILE* fp = fopen(argv[argc - 1], "r");

	if (fp == NULL)
	{
		printf("failed to open file!");
	}
	else
	{
		while ((c = fgetc(fp)) != EOF)
		{
			if (c == '\n') {
				count++;
			}
		}

		int* array = (int*)malloc(sizeof(int) * (count));


		while (fgets(string, 10, fp))
		{
			array[i] = atoi(string);
			i++;
		}

		if (doSortAscending)
		{
			qsort(array, ANZ, sizeof(int), comp);
		}
		else 
		{
			qsort(array, ANZ, sizeof(int), compDesc);
		}

		for (int i = 0; i < count; i++)
		{
			printf("%i\n", array[i]);
		}

		fclose(fp);
	}
}

int comp(const void* a, const void* b)
{
	int* pa = (int*)a;
	int* pb = (int*)b;

	return (*pb - *pa);
}

int compDesc(const void* a, const void* b)
{
	int* pa = (int*)a;
	int* pb = (int*)b;

	return (*pa - *pb);
}