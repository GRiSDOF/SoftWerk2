#include <stdio.h>
#include <conio.h>
#include "node.h"

node* makeNode(int val)
{
	node* generatedNode = malloc(sizeof(node));

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

node* connectNodes(node* root, node* leaf)
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