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
#include "fifo.c"
#include "fifo.h"

#pragma warning(disable:4996)


void main()
{
    item* fifo = NULL;
    
    if (isEmpty(fifo) == 1)
    {
        printf("Is empty\n");
    }

    fifo = put(fifo, 5);
    fifo = put(fifo, 10);
    fifo = put(fifo, 2);
    fifo = put(fifo, 8);
    fifo = put(fifo, 1);

    printf("Length of Fifo: %d\n", lengthFifo(fifo));

    if (isEmpty(fifo) == 0)
    {
        printf("Is not empty\n");
    }
    
    last(fifo);
    next(fifo);

    fifo = get(fifo);
    fifo = get(fifo);

    printf("Length of Fifo: %d\n", lengthFifo(fifo));

    deleteFifo(fifo);
}