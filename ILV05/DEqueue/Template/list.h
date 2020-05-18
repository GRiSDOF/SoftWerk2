
#pragma region structs

typedef struct _list
{
	struct _list* pNext;
	struct _list* pPrevious;
	void* data;
}list;

typedef struct _header
{
	struct _list* pFirst;
	struct _list* pLast;
	int length;
	int maxSize;
}header;

#pragma endregion

#pragma region functions

header* createList();					//create List

list*	insertFirst(header*, void*);	//insert element @ pos: first 
list*	insertLast(header*, void*);		//insert element @ end of List

void*	deleteFirst(header*);			//deletes first element of List
void*	deleteLast(header*);			//deletes last element of List
void	printList(header*);				//prints List
void	removeSList(header*);			//removes List
void*	getEntryIndex(header*, int);	//gets List entry at Index

#pragma endregion


