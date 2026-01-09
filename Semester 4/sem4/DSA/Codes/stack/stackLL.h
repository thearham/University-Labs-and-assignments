#include <iostream>
using namespace std;

class Node{
public:
    char data;
    Node* next;
    explicit Node(char x): data(x), next(nullptr) {}
};

class Stack{
private:
    Node* top;
public:
    Stack(): top(nullptr) {}

    bool isEmpty() const
    {
        return top == nullptr;
    }
    void push(char x)
    {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        cout << x << " pushed in stack\n";
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " poped" << endl;
        delete temp;
    }
    char peak() const
    {
        if (isEmpty())
        {
            cout << "stack empty!\n";
            return '\0';
        }
        return top->data;
    }
};

char* reverse_string(const char* str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    char* newStr = new char[length];
    Stack rev;
    for (int i = 0; i < length; i++) {
        rev.push(str[i]);
    }
    int i = 0;
    while (!rev.isEmpty())
    {
        newStr[i] = rev.peak();
        rev.pop();
        i++;
    }
    newStr[length] = '\0';
    cout << i << endl;
    return newStr;
}