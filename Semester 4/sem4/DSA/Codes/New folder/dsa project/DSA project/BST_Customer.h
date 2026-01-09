#include<iostream>
using namespace std;
class BST_Customer
{
public:
	string data;
	BST_Customer* left, * right;
public:
	BST_Customer()
	{
		data ;
		left = right = nullptr;
	}
	BST_Customer(string value)
	{
		data = value;
		left = right = NULL;
	}
	BST_Customer* insert(BST_Customer* root, string value)
	{
		if (root == NULL)
		{
			return new BST_Customer(value);
		}
		if (value > root->data)
		{
			root->right = insert(root->right, value);
		}
		else
			root->left = insert(root->left, value);

		return root;
	}
	void inorder(BST_Customer* root)
	{
		if (!root)
		{
			return;
		}
		inorder(root->left);
		cout << root->data << "  ";
		inorder(root->right);
	}
	BST_Customer* minValueNode(BST_Customer* node)
	{
		BST_Customer* current = node;

		/* loop down to find the leftmost leaf */
		while (current && current->left != NULL)
			current = current->left;

		return current;
	}
	
	BST_Customer* deleteNode(BST_Customer* root, string value)
	{
		// base case
		if (root == NULL)
			return root;

		if (value < root->data)
			root->left = deleteNode(root->left, value);

		else if (value > root->data)
			root->right = deleteNode(root->right, value);

		// if key is same as root's key, then This is the node
		// to be deleted
		else {
			// node has no child
			if (root->left == NULL and root->right == NULL)
				return NULL;

			// node with only one child or no child
			else if (root->left == NULL) {
				BST_Customer* temp = root->right;
				delete(root);
				return temp;
			}
			else if (root->right == NULL) {
				BST_Customer* temp = root->left;
				delete(root);
				return temp;
			}

			// node with two children: Get the inorder successor
			// (smallest in the right subtree)
			BST_Customer* temp = minValueNode(root->right);

			// Copy the inorder successor's content to this node
			root->data = temp->data;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->data);
		}
		return root;
	}
};