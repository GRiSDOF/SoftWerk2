//////////////////////////////////////////////////////////////////
//		  Salzburg University of Applied Sciences				//
//		Information Technology & Systems Management				//
//						SWE2-ILV/B								//
//////////////////////////////////////////////////////////////////
// date:			25.02.2020									//
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
#define ANZ 5

int a[ANZ] = { 34, 4, 55, 23, 6 };

int comp(const void* a, const void* b);
int ausgabe(int a[ANZ]);

//Main

void main()
{
	setlocale(LC_ALL, "de_DE");

	printf("Unsortiert\n");
	ausgabe(a);

	qsort(a, ANZ, sizeof(int), comp);

	printf("Sortiert\n");
	ausgabe(a);
}

//Functions



int comp(const void* a, const void* b)
{
	int *pa = (int*)a;
	int *pb = (int*)b;

	return (*pb - *pa);
}


int ausgabe(int a[ANZ])
{
	for (int i = 0; i < ANZ; i++)
	{
		printf("%d:  %d\n", i, a[i]);
	}
	
	return 0;
}


