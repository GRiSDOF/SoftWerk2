//////////////////////////////////////////////////////////////////
// program:         BinaryTree                                  //
// file:			binaryTree.h								//
//////////////////////////////////////////////////////////////////


#ifndef BINTREE_H
#define BINTREE_H

typedef struct bnode
{
    struct bnode* left;
    struct bnode* right;
    int val;
}BNODE;

BNODE* createTree(int val);                 // creates tree
BNODE* insertNode(BNODE* tree, int val);   // inserts node in existing tree
BNODE* searchNode(BNODE* tree, int val);    // searches node

void inorderPrint(BNODE* tree);             //prints vals of tree inorder
void preorderPrint(BNODE* tree);            //prints vals of tree preorder
void postorderPrint(BNODE* tree);           //prints vals of tree postorder

BNODE* deleteNode(BNODE* tree, int val);    // deletes single node in tree
BNODE* findMinNode(BNODE* tree);            // helper for deleting node
int sumOfNodes(BNODE* tree);                // calculates and returns sum of vals of nodes in tree

#endif                                      // !BINTREE_H