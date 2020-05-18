#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include "fifo.h"

item* put(item* fifo, int data)
{
    item* element = (item*)malloc(sizeof(item));

    if (element == NULL)
    {
        return NULL;
    }

    element->data = data;
    element->next = fifo;
    return element;

}

item* get(item* fifo)
{
    int length = lengthFifo(fifo);
    item* element = fifo;

    for (int i = 0; i < length - 2; i++)
    {
        element = element->next;
    }

    item* helper = element->next;
    helper->next = NULL;

    free(helper);

    return fifo;
}

void last(item* fifo)
{
    if (fifo != NULL)
    {
        printf("Data-top: %d\n", fifo->data);
    }

}

void next(item* fifo)
{
    int length = lengthFifo(fifo);
    item* element = fifo;

    for (int i = 0; i < length - 2; i++)
    {
        element = element->next;
    }

    printf("Data-next: %d\n", fifo->data);
}

int isEmpty(item* fifo)
{
    if (fifo == NULL)
    {
        return 1;
    }
    else {
        return 0;
    }

}

int lengthFifo(item* fifo)
{
    item* element = fifo;
    int counter = 0;

    while (counter != NULL)
    {
        element = element->next;
        counter++;
    }

    return counter;
}

void deleteFifo(item* fifo)
{
    while (fifo != NULL)
    {
        item* element = fifo;
        fifo = fifo->next;
        free(element);
    }

}