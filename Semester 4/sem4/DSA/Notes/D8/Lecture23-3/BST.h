#include "Tree.h"

class BST :public Tree
{
	void INORDER(Node*p);
	void PREORDER(Node*p);
	void POSTORDER(Node*p);
public:
	void insert(int);
	void inorder();
	void preorder();
	void postorder();
	int minimumValue();
	bool deleteNode(int);
};

bool BST::deleteNode(int value)
{
	if (root == nullptr)
		return false;

	else
	{
		Node*p = root;
		Node*c = root;
		while (1)
		{
			if (value < c->data)
			{
				p = c;
				c = c->leftChild;
			}

			else
			{
				p = c;
				c = c->rightChild;
			}

			if (c->data == value)
				break;
		}

		cout << "p->" << p->data << endl;
		cout << "c->" << c->data << endl;

		//while (1);

		if (c->leftChild == nullptr && c->rightChild == nullptr) //leaf case
		{
			if (c->data < p->data)
			{
				//left child
				delete c;
				c = nullptr;
				p->leftChild = nullptr;
				return true;
			}

			else
			{
				//right
				delete c;
				c = nullptr;
				p->rightChild = nullptr;
				return true;
			}
		}

		else if (c->leftChild != nullptr && c->rightChild == nullptr) //single child
		{
			if (c->data < p->data)
			{
				//left child of parent
				p->leftChild = c->leftChild;
				delete c;
				c = nullptr;
				return true;
			}

			else
			{
				//right child of parent
				p->rightChild = c->leftChild;
				delete c;
				c = nullptr;
				return true;
			}
		}

		else if (c->rightChild != nullptr && c->leftChild == nullptr) //single child
		{
			if (c->data < p->data)
			{
				//left child of parent
				p->leftChild = c->rightChild;
				delete c;
				c = nullptr;
				return true;
			}

			else
			{
				//right child of parent
				p->rightChild = c->rightChild;
				delete c;
				c = nullptr;
				return true;
			}
		}

	}
}


int BST::minimumValue()
{
	Node*temp = root;

	while (1)
	{
		if (temp->leftChild == nullptr)
			return temp->data;

		temp = temp->leftChild;
	}
}

void BST::POSTORDER(Node*p)
{
	if (p != nullptr)
	{
		POSTORDER(p->leftChild);
		POSTORDER(p->rightChild);
		cout << p->data << endl;
	}
}

void BST::postorder()
{
	if (root != nullptr)
		POSTORDER(root);

	else
		cout << "Tree is empty" << endl;
}

void BST::PREORDER(Node*p)
{
	if (p != nullptr)
	{
		cout << p->data << endl;
		PREORDER(p->leftChild);
		PREORDER(p->rightChild);
	}
}

void BST::preorder()
{
	if (root != nullptr)
		PREORDER(root);

	else
		cout << "Tree is empty" << endl;
}

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