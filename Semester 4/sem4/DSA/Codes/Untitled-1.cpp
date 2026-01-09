#include <iostream>
using namespace std;

void printSequence(int num){
    if(num == 0){
        return;
    }
    printSequence(num-1);
    cout << num << " ";
}
void printPattern(int num){
    if(num == 0){
        return;
    }
    printPattern(num-1);
    printSequence(num);
    cout << endl;
}
struct Node {
    int value;
    Node* left;
    Node* right;
};

void inOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }

    inOrderTraversal(node->left);
    cout << node->value << " ";
    inOrderTraversal(node->right);
}

int main(){
    printPattern(5);
}

