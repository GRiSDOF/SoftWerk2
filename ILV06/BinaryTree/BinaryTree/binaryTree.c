//////////////////////////////////////////////////////////////////
// program:         BinaryTree                                  //
// file:			binaryTree.c								//
//////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <conio.h>
#include "binaryTree.h"

BNODE* createTree(int val)
{
	BNODE* root = (BNODE*)malloc(sizeof(BNODE));

	if (root)
	{
		root->val = val;
		root->left = NULL;
		root->right = NULL;

		printf("\n\ncreated node with value = %d", val);

		return root;
	}
	else
	{
		return NULL;
	}
}

BNODE* insertNode(BNODE* tree, int val)
{
	if (tree == NULL)				// => insert root
	{
		return createTree(val);
	}
	else if (val > tree->val)		// => insert right               
	{
		tree->right = insertNode(tree->right, val);
	}
	else if (val < tree->val)		// => insert left
	{
		tree->left = insertNode(tree->left, val);
	}

	return tree;
}

BNODE* searchNode(BNODE* tree, int val)
{
	if (tree == NULL || val == tree->val)
	{
		return tree;
	}
	else if (val > tree ->val)
	{
		return searchNode(tree->right, val);
	}
	else if (val < tree ->val)
	{
		return searchNode(tree->left, val);
	}
	
	else 
	{
		return NULL;
	}
}

void inorderPrint(BNODE* tree)		// Left, Root, Right
{
	if (tree != NULL)
	{
		inorderPrint(tree->left);
		printf("%d, ", tree->val);
		inorderPrint(tree->right);
	}
}

void preorderPrint(BNODE* tree)		// Root, Left, Right
{
	if (tree != NULL)	
	{
		printf("%d, ", tree->val);
		preorderPrint(tree->left);
		preorderPrint(tree->right);
	}
}

void postorderPrint(BNODE* tree)	// Left, Right, Root
{
	if (tree != NULL)
	{
		postorderPrint(tree->left);
		postorderPrint(tree->right);
		printf("%d, ", tree->val);
	}
}

BNODE* deleteNode(BNODE* tree, int val)
{
	if (tree == NULL)
	{
		return tree;
	}

	if (val > tree->val)
	{
		tree->right = deleteNode(tree->right, val);
	}
	else if (val < tree->val)
	{
		tree->left = deleteNode(tree->left, val);
	}
	else 
	{
		if (tree->left == NULL) 
		{
			BNODE* temp = tree->right;
			free(tree);

			return temp;
		}
		else if (tree->right == NULL) 
		{
			struct BNODE* temp = tree->left;
			free(tree);

			return temp;
		}

		BNODE* temp = findMinNode(tree->right);

		tree->val = temp->val;
		tree->right = deleteNode(tree->right, temp->val);
	}

	return tree;
}

BNODE* findMinNode(BNODE* tree) 
{
	if (tree->left == NULL)
	{
		return tree;
	}
	else
	{
		return findMinNode(tree->left);
	}
}

int sumOfNodes(BNODE* tree)
{
	if (tree != NULL)
	{
		return (tree->val + sumOfNodes(tree->left) + sumOfNodes(tree->right));
	}
	else
	{
		return 0;
	}
}