#include "BST.h"

int main()
{
	BST bst;
	bst.insert(26);
	bst.insert(100);
	bst.insert(10);
	bst.insert(50);
	bst.insert(56);
	bst.insert(-3);
	bst.insert(7);

	bst.inorder();

	return 0;
}