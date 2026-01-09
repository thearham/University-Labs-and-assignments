#include "Node.h"

class LinkedList
{
protected:
	Node*head;
	Node*tail;
public:
	LinkedList();
	virtual void insert(int value) = 0;
};

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}