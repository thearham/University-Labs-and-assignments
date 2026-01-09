#include <iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    node* root;

    node* insertRecursive(node* root, int val) {
        if (root == nullptr)
            return new node(val);
        
        if (val < root->val)
            root->left = insertRecursive(root->left, val);
        else if (val > root->val)
            root->right = insertRecursive(root->right, val);

        return root;
    }

    int heightRecursive(node* root) {
        if (root == nullptr)
            return 0;
        
        int leftHeight = heightRecursive(root->left);
        int rightHeight = heightRecursive(root->right);
        
        return 1 + max(leftHeight, rightHeight);
    }

public:
    BinarySearchTree() : root(nullptr) {}
	
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    int height() {
        return heightRecursive(root);
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    cout << "Height of the Binary Search Tree: " << bst.height() << endl;

    return 0;
}
