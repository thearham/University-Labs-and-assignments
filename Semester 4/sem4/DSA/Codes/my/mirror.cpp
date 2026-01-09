#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

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


void mirror(Node* node) {
    if (node == NULL) {
        return;
    }
    else {
        Node* temp;
        
        mirror(node->left);
        mirror(node->right);
    
        
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}


void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
}

int main()
{
    Node* root = NULL;
    root = insert(root,35);
    insert(root,25);
    insert(root, 140);
    insert(root,170);
    insert(root, 6);
    insert(root, 2);

    inorder(root);
    cout << endl;
    mirror(root);
    inorder(root);
    return 0;
}