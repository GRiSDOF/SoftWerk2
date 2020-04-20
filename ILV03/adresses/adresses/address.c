#include <stdio.h>
#include <conio.h>
#include "address.h"

void help()
{
	printf("\n\description of the options:");
	printf("\n\noption \t\t\t description");
	printf("\nx -h \t\t\t delivering a short description of the options");
	printf("\nx -p \t\t\t print all addresses");
	printf("\nx -s \t\t\t print all addresses sorted by names");
	printf("\nx -f template \t\t\t sorting all addresses by name and search for template");
}

ADDRESS* read(ADDRESS* p)
{
	FILE* file;
	char tempArray[100];

	int n = 0;

	file = fopen("temp.txt", "r");

	fgets(tempArray, 10, file);
	n = atoi(tempArray);

	for (int i = 0; i != n; i++)
	{
		fgets(tempArray, LEN, file);
		strcpy(p[i].name, tempArray);
		fgets(tempArray, LEN, file);
		strcpy(p[i].surName, tempArray);
		fgets(tempArray, LEN, file);
		p[i].year = atoi(tempArray);
	}
	
	return p;
}

int returnN()
{
	FILE* file;
	char tempArray[100];

	file = fopen("temp.txt", "r");

	fgets(tempArray, 10, file);
	return atoi(tempArray);
}

void print(ADDRESS* p, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\n%s\t", p[i].name);
		printf("%s\t", p[i].surName);
		printf("%i", p[i].year);
	}
}

void sortName(ADDRESS* p, int n)
{
	qsort(p, n, sizeof(ADDRESS), compare);
}

void searchName(ADDRESS* p, int n, char* name)
{
	for (int i = 0; i <= n; i++)
	{
		if (strstr(p[i].surName, name) != 0)
		{
			printf("Found: %s, %s\n", p[i].surName, p[i].name);
		}
	}
}

int compare(const void* a, const void* b)
{
	ADDRESS* pa = a;
	ADDRESS* pb = b;

	return (strcmp(pa->surName, pb->surName));
}