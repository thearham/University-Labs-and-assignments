#include <iostream>
using namespace std;



template<class T>
class node
{
public:
	T data;
	node *left, *right;
	node()
	{
		left = right = 0;
	}
	node(T &e, node *l = 0, node* r = 0)
	{
		data = e;
		left = l;
		right = r;
	}

};

  

template<class T>
class BST
{
private:
	node<T> *root;
	int no_nodes;
public:
	BST();
	bool isEmpty()const;
	void insert(node<T>*r, node<T>*p, T x);
	bool search(node<T>*r, T x)const;
	void remove(T x);
	int getSize()const;
	node<T>* getRoot()const;
	void display(node<T>*)const;
	void destructor(node<T>* r);
	~BST();
};

template<class T>
BST<T>::BST()
{
	root = 0;
	no_nodes = 0;
}

template<class T>
bool BST<T>::isEmpty()const
{
	if (root == 0) return 1;
	else return 0;
}

template<class T>
void BST<T>::insert(node<T>*r, node<T>*p, T x)
{
	if (r == 0)
	{
		r = new node<T>(x);
		no_nodes++;
		if (this->root == 0){
			root = r;
		}
		else{
			if (x < p->data){
				p->left = r;
			}
			else{
				p->right = r;
			}
		}
	}
	else{
		if (x >= r->data){
			insert(r->right, r, x);
		}
		else{
			insert(r->left, r, x);
		}
	}
}

template<class T>
bool BST<T>::search(node<T>*r, T x)const
{
	if (r == 0){
		return false;
	}
	else{
		if (x == r->data){
			return true;
		}
		else if (x > r->data){
			return search(r->right, x);
		}
		else{
			return search(r->left, x);
		}
	}
}
template<class T>
void BST<T>::remove(T x)
{
	bool found = 0;
	node<T> *temp = root, *parent = 0;
	while (temp != 0)
	{
		if (x == temp->data) { found = 1; break; }
		else if (x > temp->data) { parent = temp; temp = temp->right; }
		else { parent = temp; temp = temp->left; }
	}
	if (!found) { cerr << "Value Does not exist.\n"; return; }

	if (temp->left == 0 && temp->right == 0)  /// leaf case
	{
		if (parent == 0){
			delete temp;
			root = 0;
			no_nodes--;
		}
		else{
			if (x > parent->data) parent->right = 0;
			else parent->left = 0;
			delete temp;
			no_nodes--;
		}
	}
	else if (temp->right != 0 && temp->left == 0 || temp->right == 0 && temp->left != 0) /// exact one child
	{
		if (temp->right != 0 && temp->left == 0)
		{
			if (parent == 0)
			{
				root = temp->right;
			}
			else
			{
				parent->right = temp->right;
			}

		}
		else
		{
			if (parent == 0)
			{
				root = temp->right;
			}
			else
			{
				parent->left = temp->left;
			}
		}
		delete temp;
		no_nodes--;
	}
	else        /// two children
	{
		parent = temp;
		node<T>* succ = temp->right;
		while (succ->left != 0)
		{
			parent = succ;
			succ = succ->left;
		}
		temp->data = succ->data;

		if (succ->left == 0 && succ->right == 0)  /// leaf case
		{
			parent->right = 0;
			delete succ;
			no_nodes--;
		}
		else if (succ->right != 0 && succ->left == 0 || succ->right == 0 && succ->left != 0) /// exact one child
		{
			parent->right = succ->right;
			delete succ;
			no_nodes--;
		}
	}
}
template<class T>
int BST<T>::getSize()const
{
	return no_nodes;
}

template<class T>
node<T>* BST<T>::getRoot()const
{
	return root;
}

template<class T>
void BST<T>::display(node<T>* r)const
{
	if (r != 0)
	{
		cout << r->data << " ";
		display(r->left);

		display(r->right);
	}
}
template<class T>
BST<T>::~BST()
{
	//delete root;
	destructor(root);
}
template<class T>
void BST<T>::destructor(node<T>* r)
{
	if (r != 0){
		destructor(r->left);
		destructor(r->right);
		delete r;
	}
}




int main()
{
	BST<int> tree;
	tree.insert(tree.getRoot(), 0, 4);
	tree.insert(tree.getRoot(), 0, 5);
	tree.insert(tree.getRoot(), 0, 7);
	tree.insert(tree.getRoot(), 0, 1);
	tree.insert(tree.getRoot(), 0, 3);
	cout << "Pre order traversal of tree: \n";
	tree.display(tree.getRoot()); cout << endl << endl;
	cout << tree.search(tree.getRoot(), 7) << endl;
	return 1;

}
