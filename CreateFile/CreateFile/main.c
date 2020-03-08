////////////////////////////////////////////////////////////
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
#include <time.h>
#include <stdbool.h>
#include <string.h>

#pragma warning(disable:4996)

void main(int argc, char* argv[]) {
	
	int n = 100;
	int max = 100;

	srand(time(NULL));


	for (int i = 0; i < argc - 1; i++) 
	{

		if (strcmp(argv[i], "-h") == 0) 
		{
			printf("\n\ndescription of the options:");
			printf("\n\noption \t\t description");
			printf("\nx -h \t\t delivering a short description of the options");
			printf("\nx -n \t\t amount of numbers (default: 100)");
			printf("\nx -r \t\t range of numbers (default: 100)");
			
		}

		else if (strcmp(argv[i], "-n") == 0) 
		{
			if (*argv[i + 1] >= 48 && *argv[i + 1] <= 57) 
			{
				n = atoi(argv[i + 1]);
			}
		}

		else if (strcmp(argv[i], "-r") == 0) 
		{
			if (*argv[i + 1] >= 48 && *argv[i + 1] <= 57) 
			{
				max = atoi(argv[i + 1]);
			}
		}

	}

	FILE* fp = fopen(argv[argc - 1], "w");

	if (fp == NULL) 
	{
		printf("failed to open file!");
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			fprintf(fp, "%i\n", rand() % max);
		}

		fclose(fp);
	}
}