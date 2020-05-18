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
#include "lifo.c"
#include "lifo.h"

#pragma warning(disable:4996)


void main()
{
    item* lifo = NULL;

    if (isEmpty(lifo) == 1)
    {
        printf("Is empty\n");
    }

    lifo = push(lifo, 5);
    lifo = push(lifo, 10);
    lifo = push(lifo, 2);
    lifo = push(lifo, 8);
    lifo = push(lifo, 1);

    printf("Length of Lifo: %d\n", lengthFifo(lifo));

    if (isEmpty(lifo) == 0)
    {
        printf("Is not empty\n");
    }

    last(lifo);
    next(lifo);

    lifo = pop(lifo);
    lifo = pop(lifo);

    printf("Length of Fifo: %d\n", lengthLifo(lifo));

    deleteLifo(lifo);
}