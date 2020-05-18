#pragma region structs

typedef struct _item {
    int data;
    struct _item* next;
}item;

#pragma endregion


#pragma region functions

item* put(item*, int);
item* get(item*);
void last(item*);
void next(item*);
int isEmpty(item*);
int lengthFifo(item*);
void deleteFifo(item*);

#pragma endregion