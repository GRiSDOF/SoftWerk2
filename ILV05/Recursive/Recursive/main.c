//////////////////////////////////////////////////////////////////
//		  Salzburg University of Applied Sciences				//
//		Information Technology & Systems Management				//
//						SWE2-ILV/B								//
//////////////////////////////////////////////////////////////////
// date:			05.05.2020									//
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


void numbers(int);
int sum(int);
int fibonacci(int);


void main()
{
	int n = 10;

	numbers(n);
	printf("\n");
	printf("%d", sum(n));
	printf("\n");
	printf("%d", fibonacci(n));
	printf("\n");
}

void numbers(int n)
{
	if (n != 0)
	{
		printf("%d\t", n);
		numbers(n - 1);
	}
}
int sum(int n)
{
	if (n != 0)
	{
		return n + sum(n - 1);
	}
	else
	{
		return n;
	}
}

int fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return (fibonacci(n - 1) + fibonacci(n - 2));
	}
}