//////////////////////////////////////////////////////////////////
//		  Salzburg University of Applied Sciences				//
//		Information Technology & Systems Management				//
//						SWE2-ILV/B								//
//////////////////////////////////////////////////////////////////
// date:			03.06.2020									//
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

void print(const void* data);
void printIterative(int* base, int nmemb, int size, void* (printData)(const void*));
void printRecursive(int* base, int nmemb, int size, void* (printData)(const void*));


void main(int argc, char* argv[])
{
	setlocale(LC_ALL, "de_DE");

	int array[] = { 1, 2, 3, 4 };

	printf("Iterative:\n");
	printIterative(array, (sizeof(array) / sizeof(int)), sizeof(int), print);

	printf("\n\nRecursive:\n");
	printRecursive(array, (sizeof(array) / sizeof(int)), sizeof(int), print);
}

void print(const void* data)
{
	printf("%i\n", *(int*)data);
}

void printIterative(int* base, int nmemb, int size, void (*printData)(const void*))
{
	for (int i = 0; i < nmemb; i++)
    {
        (*printData)(base + i);
    }

}

void printRecursive(int* base, int nmemb, int size, void (*printData)(const void*))
{
	if (nmemb != 0)
	{
		(*printData)(base);
		printRecursive(base+1, nmemb-1, size, printData);
	}
}
