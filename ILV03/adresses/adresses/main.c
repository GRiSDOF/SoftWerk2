//////////////////////////////////////////////////////////////////
//		  Salzburg University of Applied Sciences				//
//		Information Technology & Systems Management				//
//						SWE2-ILV/B								//
//////////////////////////////////////////////////////////////////
// date:			20.04.2020									//
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
#include "address.h"
#include "address.c"

#pragma warning(disable:4996)


void main(int argc, const char* argv[])
{
	ADDRESS* address;
	char* name;

	int i = 0;
	int n = returnN();

	printf("help: -h\n");

	address = read(address);


	while (argv[i++] != NULL)
	{

		if ((strcmp(argv[i], "-h")) == 0)
		{
			help();
		}

		if ((strcmp(argv[i], "-p")) == 0)
		{
			print(address, n);
		}

		if (strcmp(argv[i], "-s") == 0)
		{
			sortName(address, n);
		}

		if (strcmp(argv[i], "-f") == 0)
		{
			name = argv[i + 1];
			searchName(address, n, name);
		}
	}
}


