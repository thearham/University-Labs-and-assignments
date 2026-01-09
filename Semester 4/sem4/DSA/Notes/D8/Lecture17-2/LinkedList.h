#include "Node.h"
#include <iostream>
using namespace std;


class LinkedList
{
protected:
	Node* head;
public:
	virtual void insertAtHead(int value) = 0;
	virtual void insertAtTail(int value) = 0;
	virtual void insertSorted(int value) = 0;
	virtual void display() = 0;
	virtual int deleteFromHead() = 0;
	virtual int deleteFromTail() = 0;
	virtual bool deleteValue(int) = 0;

	LinkedList();

};

LinkedList::LinkedList()
{
	head = nullptr;
}


