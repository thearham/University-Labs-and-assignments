#include "LinkedList.h"
class myLL :public LinkedList
{
public:
	void insertAtTail(int value);
	void display();
};

void myLL::insertAtTail (int value)
{
	Node*nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	if (head == nullptr && tail == nullptr)//empty LL
	{
		head = nn;
		tail = nn;
	}

	else
	{
		tail->next = nn;
		tail = nn;
	}
}

void myLL::display()
{
	Node*temp = head;

	while (1)
	{
		cout << temp->data << endl;
		temp = temp->next;

		if (temp == nullptr)
			break;
	}
}