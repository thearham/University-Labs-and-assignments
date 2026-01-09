#include "Tree.h"

class BST :public Tree
{
	void INORDER(Node*p);
public:
	void insert(int);
	void inorder();
};

void BST::INORDER(Node*p)
{
	if (p != nullptr)
	{
		INORDER(p->leftChild);
		cout << p->data << endl;
		INORDER(p->rightChild);
	}
}

void BST::inorder()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		INORDER(root);
}

void BST::insert(int value)
{
	Node*nn = new Node;
	nn->data = value;
	nn->leftChild = nullptr;
	nn->rightChild = nullptr;

	if (root == nullptr) //empty BST
		root = nn;

	else
	{
		Node*temp = root;
		while (1)
		{
			if (value < temp->data) //left
			{
				if (temp->leftChild == nullptr)
				{
					temp->leftChild = nn;
					break;
				}
				else
					temp = temp->leftChild;
			}

			else //right
			{
				if (temp->rightChild == nullptr)
				{
					temp->rightChild = nn;
					break;
				}

				else
					temp = temp->rightChild;
			}
		}
	}
}