#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include "lifo.h"

item* push(item* lifo, int data)
{
    item* element = (item*)malloc(sizeof(item));

    if (element == NULL)
    {
        return NULL;
    }

    element->data = data;
    element->next = lifo;

    return element;
}

item* pop(item* lifo)
{
    item* element = lifo;

    lifo = lifo->next;
    free(element);

    return lifo;
}

void top(item* lifo)
{
    if (lifo != NULL) 
    {
        printf("Data-Top: %d\n", lifo->data);
    }
}


int isEmpty(item* lifo)
{
    if (lifo == NULL)
    {
        return 1;
    }
    else {
        return 0;
    }
}

int lengthLifo(item* lifo)
{
    item* element = lifo;
    int counter = 0;

    while (element != NULL) 
    {
        element = element->next;
        counter++;
    }

    return counter;
}

void deleteLifo(item* lifo)
{
    while (lifo != NULL)
    {
        item* element = lifo;
        element = element->next;

        free(element);
    }
}
