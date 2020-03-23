#include <stdio.h>
#include <conio.h>
#include "node.h"

struct node* makeNode(int val)
{
	struct node* generatedNode = malloc(sizeof(struct node));

	if (generatedNode)
	{
		generatedNode->edge = NULL;
		generatedNode->val = val;

		return generatedNode;
	}
	else 
	{
		return NULL;
	}
}

struct node* connectNodes(struct node* root, struct node* leaf)
{
	if (root == NULL || leaf == NULL)
	{
		return NULL;
	}
	else 
	{
		root->edge = leaf;
		return root;
	}
}