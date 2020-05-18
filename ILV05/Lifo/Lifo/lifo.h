#pragma region structs

typedef struct _item {
    int data;
    struct _item* next;
}item;

#pragma endregion


#pragma region functions

item* push(item*, int);
item* pop(item*);
void top(item*);
int isEmpty(item*);
int lengthLifo(item*);
void deleteLifo(item*);

#pragma endregion