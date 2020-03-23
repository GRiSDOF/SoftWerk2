#include <stdio.h>
#include <conio.h>
#include "node.c"
#include "node.h"

void main(int argc, char* argv[])
{
	struct node* root = makeNode(100);

	if (root)
	{
		struct node* child = makeNode(10);

		if (child)
		{
			root->edge = child;
			printf("%d\n", root->edge->val);
		}
		printf("%d\n", root->val);
	}
}