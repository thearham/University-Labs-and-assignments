#include "LinkedList.h"
class myLL :public LinkedList
{
public:
	void insert(int value);
};

void myLL::insert(int value)
{
	Node*newNode = new Node;
	newNode->next = nullptr;
	newNode->data = value;

	if (head == nullptr && tail == nullptr) //LL is empty
	{
		head = newNode;
		tail = newNode;
	}

	else //non empty LL
	{

	}
}