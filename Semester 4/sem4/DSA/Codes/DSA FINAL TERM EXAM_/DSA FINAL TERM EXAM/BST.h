#include "Tree.h"

class BST:public Tree
{
	void INORDER(Node* p);
	void POSTORDER(Node* p);
	void PREORDER(Node* p);
public:
	void insert(int value);
	void inorder();
	void postorder();
	void preorder();
	bool deleteValue(int value);
};

bool BST::deleteValue(int value)
{
	if (root == nullptr)	
		return false;
		
	else if (root->data == value && root->left == nullptr && root->right == nullptr) 
	{
		delete root;
		root = nullptr;
	}
	
	
	
	else	
	{
		Node*c = root;
		Node*p = root;
		
		while(true)
		{
			if (value == c->data)	
			{
				// 2 children case
				if (c->left != nullptr && c->right != nullptr)
				{
					Node* t = c;

					p = t;
					c = t->right;

					while (c->left!=nullptr)
					{
						p = c;
						c = c -> left;
					}

					t->data = c->data;
				}

				//leaf case condition:
				if (c->left == nullptr && c->right == nullptr)
				{
					if (c->data < p->data) //left child of parent
					{
						delete c;
						c = nullptr;
						p->left = nullptr;
					}
					
					else	//right child
					{
						delete c;
						c = nullptr;
						p->right = nullptr;
					}
				}
				
				//single child case where LEFT exists
				else if (c->left != nullptr && c->right == nullptr)
				{
					if (c->data < p->data) //left child of parent
					{
						p->left = c->left;
						delete c;
						c = nullptr;
					}

					else //right child of parent
					{
						p->right = c->left;
						delete c;
						c = nullptr;
					}

				}

				//single child case where RIGHT exists
				else if (c->left == nullptr && c->right != nullptr)
				{
					if (c->data < p->data) //left child of parent
					{
						p->left = c->right;
						delete c;
						c = nullptr;
					}

					else //right child of parent
					{
						p->right = c->right;
						delete c;
						c = nullptr;
					}

				}


				return true;
			}
			
			else
			{
				if (value < c->data)
				{
					p = c;
					c = c->left;
				}
				
				else
				{
					p = c;
					c = c->right;
				}
			}
		}
	}
}

void BST::PREORDER(Node* p)
{
	if (p!=nullptr)
	{
		cout << p->data << " ";
		PREORDER(p->left);
		PREORDER(p->right);
		
	}
}

void BST::POSTORDER(Node* p)
{
	if (p!=nullptr)
	{
		POSTORDER(p->left);
		POSTORDER(p->right);
		cout << p->data << " ";
	}
}

void BST::INORDER(Node* p)
{
	if (p!=nullptr)
	{
		INORDER(p->left);
		cout << p->data << " ";
		INORDER(p->right);
	}
}

void BST::preorder()
{
	if (root == nullptr)
		cout << "Tree is empty"  << endl;
		
	else
		PREORDER(root);
}


void BST::postorder()
{
	if (root == nullptr)
		cout << "Tree is empty"  << endl;
		
	else
		POSTORDER(root);
}


void BST::inorder()
{
	if (root == nullptr)
		cout << "Tree is empty"  << endl;
		
	else
		INORDER(root);
}

void BST::insert(int value)
{
	Node *n = new Node;
	n->left = nullptr;
	n->right = nullptr;
	n->data = value;
	
	if (root == nullptr)
	{
		root = n;
	}
	
	else
	{
		Node*t = root;
		
		while(1)
		{
			if (value<t->data)	//left child case
			{
				if (t->left==nullptr)	//insert the value 
				{
					t->left = n;
					break;
				}
				
				else
				{
					t = t->left;
				}
			}
			
			else				//right child case
			{
				if (t->right == nullptr)	//insert value
				{
					t->right = n;
					break;
				}
				
				else
				{
					t=t->right;
				}
				
			}
				
		}
	}
	
}