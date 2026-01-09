#include "BST.h"

int main()
{
	BST bst;
	bst.insert(26);
	bst.insert(100);
	bst.insert(50);
	bst.insert(56);
	bst.insert(3);
	bst.insert(7);
	bst.insert(0);
	bst.insert(150);
	bst.insert(999);
	bst.insert(7);
	bst.insert(125);
	bst.insert(120);
	bst.insert(105);

	cout << bst.deleteNode(100) << endl;

	cout << "Inorder" << endl;

	bst.inorder();

	return 0;
}