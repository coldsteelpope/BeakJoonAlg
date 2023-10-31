#include "BinarySearchTree.h"

void PrintSearchResult(int SearchTarget, BSTNode* Result)
{
	if (Result != NULL)
		printf("Found: %d \n", Result->Data);
	else
		printf("Not Found: %d \n", SearchTarget);
}

int main(void)
{
	BSTNode* Tree = BST_CreateNode(123);
	BSTNode* Node = NULL;

	BST_InsertNode(Tree, BST_CreateNode(22));
	BST_InsertNode(Tree, BST_CreateNode(9918));

	BST_InsertNode(Tree, BST_CreateNode(424));
	BST_InsertNode(Tree, BST_CreateNode(17));
	BST_InsertNode(Tree, BST_CreateNode(3));

	BST_InsertNode(Tree, BST_CreateNode(98));
	BST_InsertNode(Tree, BST_CreateNode(34));
	
	BST_InorderPrintTree(Tree);
	printf("\n");

	BST_DestroyTree(Tree);
}