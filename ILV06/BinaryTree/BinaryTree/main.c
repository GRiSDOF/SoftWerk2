//////////////////////////////////////////////////////////////////
//		  Salzburg University of Applied Sciences				//						
//		Information Technology & Systems Management				//							
//						SWE2-ILV/B								//
//////////////////////////////////////////////////////////////////
// date:			17.04.2020									//
//																//					
//																//
// author:			Christoph Lenzbauer							//				
// email:			clenzbauer.its-b2019@fh-salzburg.ac.at		//									
//////////////////////////////////////////////////////////////////
// program:         BinaryTree                                  //
// file:			main.c										//
//////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <conio.h>
#include "binaryTree.h"

void main()
{
	BNODE* pRoot = createTree(30);

	insertNode(pRoot, 20);
	insertNode(pRoot, 40);
	insertNode(pRoot, 30);
	insertNode(pRoot, 10);
	insertNode(pRoot, 90);
	insertNode(pRoot, 25);
	insertNode(pRoot, 15);
	insertNode(pRoot, 65);

	printf("\n\nInorder: ");
	inorderPrint(pRoot);

	printf("\n\nPreorder: ");
	preorderPrint(pRoot);

	printf("\n\nPostorder: ");
	postorderPrint(pRoot);

	if (searchNode(pRoot, 15))
	{
		printf("\n\nValue = 15 found");
	}
	else
	{
		printf("\\nnValue = 15 not found");
	}

	printf("\n\nSum of binary tree = %d", sumOfNodes(pRoot));
	
	deleteNode(pRoot, 15);
	deleteNode(pRoot, 65);

	printf("\n\nInorder: ");
	inorderPrint(pRoot);

	printf("\n\nSum of binary tree = %d", sumOfNodes(pRoot));
}