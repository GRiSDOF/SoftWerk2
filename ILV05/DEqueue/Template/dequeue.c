#include "list.h"
#include "list.c"
#include "dequeue.h"
#include <stdbool.h>

header* createDEQueue(int size)
{
    header* queue = createList();

    if (queue) 
    {
        queue->maxSize = size;
        return queue;
    }
    else 
    {
        return NULL;
    }
}

list* insertFirstDQ(header* queue, int data)
{
    if (queue->length <= queue->maxSize) 
    {
        list* node = insertLast(queue, data);
        return node;
    }
    else
    {
        return NULL;
    }
}

list* insertLastDQ(header* queue, int data)
{
    if (queue->length <= queue->maxSize)
    {
        list* node = insertFirst(queue, data);
        return node;
    }
    else
    {
        return NULL;
    }
}

void* removeFirstDQ(header* queue)
{
    return deleteLast(queue);
}

void* removeLastDQ(header* queue)
{
    return deleteFirst(queue);
}

list* examineFirstDQ(header* queue)
{
    if (queue->length > 0)
    {
        return queue->pLast;
    }
    else
    {
        return NULL;
    }
}

list* examineLastDQ(header* queue)
{
    if (queue->length > 0)
    {
        return queue->pFirst;
    }
    else
    {
        return NULL;
    }
}

bool isEmptyDQ(header* queue)
{
    if (queue->length == 0)
    {
        return true;
    }
    
    return false;
}

void deleteQueue(header* queue)
{
    removeList(queue);
}