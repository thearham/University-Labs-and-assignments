#include <iostream>
using namespace std;

class node{
public:
    char data;
    node* next;
    node* prev;
    node(char x) : data(x), next(NULL), prev(NULL) {}
};

bool palindrome(node*& head, node*& tail)
{
    node* temp1 = head;
    node* temp2 = tail;

    bool check = false;

    while (temp1->next != NULL && temp2->prev != NULL)
    {
        if (temp1->data == temp2->data)
        {
            check = true;
            temp1 = temp1->next;
            temp2 = temp2->prev;
        }
        else
        {
            break;
        }
        
    }
    return check;
}

int main(){
    node* head = new node('a');
    head->next = new node('t');
    head->next->prev = head;
    node* tail = new node('i');
    tail->prev = head->next->prev;
    
    cout << palindrome(head, tail) << endl;
    return 0;
}