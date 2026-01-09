#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void preorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    void inorderTraversal() {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }

    void postorderTraversal() {
        cout << "Postorder traversal: ";
        postorder(root);
        cout << endl;
    }

    void preorderTraversal() {
        cout << "Preorder traversal: ";
        preorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    bst.inorderTraversal();
    bst.postorderTraversal();
    bst.preorderTraversal();

    return 0;
}
