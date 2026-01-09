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

void Smallest(Node* node, int& ans) {
    if (node == NULL) {
        return;
    }

    Smallest(node->left, ans);

    
    if (node->data > 100 && (ans == -1 || node->data < ans)) {
        ans = node->data;
    }

    Smallest(node->right, ans);
}

// int Smallest(Node* root, int* arr)
// {
//     static int index = 0;
//     if (root == NULL) return 0;
//     if (root->data > 100){
//         arr[index] = root->data;
//         index++;
//     }
//     auto SmallestElementInArray = [](int* arr, int size) -> int
//     {
//         int smallest = arr[0];
//         for (int i = 0; i < size; i++)
//         {
//             if (arr[i] < smallest)
//             {
//                 smallest = arr[i];
//             }
//         }
//         return smallest;
//     };
//     Smallest(root->left, arr);
//     Smallest(root->right, arr);
//     return SmallestElementInArray(arr, index);
// }
/*
the index variable is incremented each time Smallest is called.
Because index is static, it retains its value between calls, so it will continue to 
increment each time the function is called.
If index were a local variable (not static), it would be reinitialized to 0 each 
time the function is called, and it would not store the values in array at appropriate indexes.
*/
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
    int ans = -1;
    Smallest(root, ans);
    cout << ans << endl;
    return 0;
}