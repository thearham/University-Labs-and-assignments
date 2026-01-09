#include <iostream>>
#include "Node.h"
using namespace std;

class LinkedList
{
protected:
    Node* head;
    Node *tail;
public:
    LinkedList();
    virtual void insertAtTail(int value) = 0;
    virtual void display() = 0;
    virtual void insertAtHead(int value) = 0;
    virtual int deleteFromHead() = 0;
};

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}