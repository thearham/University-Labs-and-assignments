#include <iostream>
#include "Node.h"
using namespace std;

class Tree
{
protected:
	Node*root;
public:
	Tree();
	virtual void insert(int) = 0;
	virtual void inorder() = 0;
	virtual void preorder() = 0;
	virtual void postorder() = 0;
	virtual bool deleteNode(int) = 0;
};

Tree::Tree()
{
	root = nullptr;
}