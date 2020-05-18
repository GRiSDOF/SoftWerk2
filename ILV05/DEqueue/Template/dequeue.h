#include "list.h"


header* createDEQueue(int size); 
list*	insertFirstDQ(header* queue, int data);
list*	insertLastDQ(header* queue, int data);

void*	removeFirstDQ(header* queue);
void*	removeLastDQ(header* queue);

list*	examineFirstDQ(header* queue);
list*	examineLastDQ(header* queue);

bool	isEmptyDQ(header* queue);
void	deleteQueue(header* queue);

