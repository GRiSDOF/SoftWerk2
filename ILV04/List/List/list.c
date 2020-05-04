#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

header* createList()
{
	header* head = (header*)malloc(sizeof(header));

	if (head == NULL)
	{
		return NULL;
	}
	else 
	{
		head->length = 0;
		head->pFirst = NULL;
		head->pLast = NULL;

		return head;
	}
}

list* insertFirst(header* mainList, void* data)
{
	list* element = (list*)malloc(sizeof(list));

	if (element == NULL)
	{
		return NULL;
	}
	else
	{
		element->data = data;
		element->pNext = mainList->pFirst;

		mainList->pFirst = element;
		
		if (mainList->length == 0)
		{
			mainList->pLast = element;
		}

		mainList->length++;

		return element;
	}
}

list* insertLast(header* mainList, void* data)
{
	list* element = (list*)malloc(sizeof(list));

	if (element == NULL)
	{
		return NULL;
	}
	else
	{
		element->data = data;
		element->pNext = NULL;

		mainList->pFirst = element;

		if (mainList->length == 0)
		{
			mainList->pFirst = element;
		}
		else
		{
			mainList->pLast->pNext = element;
		}

		mainList->pLast = element;
		mainList->length++;

		return element;
	}
}

void* deleteFirst(header* mainList)
{
	list* tmpElement;
	void* tmpData = NULL;

	if (mainList != NULL)
	{
		tmpElement = mainList->pFirst;
		tmpData = tmpElement->data;

		mainList->pFirst = tmpElement->pNext;
		mainList->length--;

		free(tmpElement);
	}
	else
	{
		return tmpData;
	}

	return tmpData;
}

void* deleteLast(header* mainList)
{
	list* tmpElement;
	list* helper;
	void* tmpData = NULL;;

	if (mainList != NULL)
	{

		tmpElement = mainList->pLast;
		tmpData = tmpElement->data;

		helper = mainList->pFirst;
		mainList->pLast = helper;

		for (int i = 0; i < mainList->length - 1; i++) 
		{
			mainList->pLast = helper;
			helper = helper->pNext;
		}

		mainList->length--;

		free(tmpElement);
	}
	else
	{
		return tmpData;
	}

	return tmpData;
}

void printList(header* mainList)
{
	list* element = mainList->pFirst;

	for (int i = 0; i <= mainList->length-1; i++)
	{
		printf("%d. %s\n", i, element->data);

		element = element->pNext;
	}
}

void removeList(header* mainList)
{
	free(mainList);
}

void* getEntryIndex(header* mainList, int i)
{
	if (i > 0 && i <= mainList->length)
	{
		list* element;

		element = mainList->pFirst;

		for (int index = 1; index < i; index++)
		{
			element = element->pNext;
		}
			
		return element->data;

	}
	else
	{
		return NULL;
	}
}