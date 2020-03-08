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

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "de_DE");

	int* array[] = (int*)malloc(sizeof(int) * (argc - 1));

	int help = 0;
	bool swapped = true;

	while (swapped)
	{
		swapped = false;

		for (int i = 0; i < argc -1 ; i++)
		{
			if (array[i] > array[i + 1])
			{
				help = array[i];
				array[i] = array[i + 1];
				array[i + 1] = help;

				swapped = true;
			}
		}
	}

	for (int i = 0; i < argc; i++)
	{
		printf("array[%d] = %d ", i, array[i]);
		printf("\n");
	}

	return 0;
}