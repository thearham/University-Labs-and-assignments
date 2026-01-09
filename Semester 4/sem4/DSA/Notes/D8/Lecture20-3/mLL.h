#include "LinkedList.h"

class myLL :public LinkedList
{
public:
	void insertAtHead(int);
	void insertAtTail(int);
	void displayFromHead();
	int deleteFromHead();
	int deleteFromTail();
};

int myLL::deleteFromHead()
{
	if (head == nullptr)
		return NULL;

	else if (head->next == head) //single node
	{
		int RV = head->data;
		delete head;
		head = nullptr;
		return RV;
	}

	else
	{
		head = head->next; //crucial statement
		Node*temp = head->prev;
		temp->prev->next = head;
		head->prev = temp->prev;
		int RV = temp->data;
		delete temp;
		temp = nullptr;
		return RV;
	}
}

int myLL::deleteFromTail()
{
	if (head == nullptr)
		return NULL;

	else if (head->next == head) //single node
	{
		int RV = head->data;
		delete head;
		head = nullptr;
		return RV;
	}

	else
	{
		Node*temp = head->prev;
		temp->prev->next = head;
		head->prev = temp->prev;
		int RV = temp->data;
		delete temp;
		temp = nullptr;
		return RV;
	}
}

void myLL::insertAtHead(int value)
{
	Node*n = new Node;
	n->data = value;
	n->next = nullptr;
	n->prev = nullptr;
	
	if (head == nullptr)
	{
		head = n;
		head->next = head;
		head->prev = head;
	}

	else
	{
		n->next = head;
		n->prev = head->prev;
		head->prev = n;
		head->prev->prev->next = n;
		head = n;
	}
}

void myLL::insertAtTail(int value)
{
	Node*n = new Node;
	n->data = value;
	n->next = nullptr;
	n->prev = nullptr;

	if (head == nullptr)
	{
		head = n;
		head->next = head;
		head->prev = head;
	}

	else
	{
		n->next = head;
		n->prev = head->prev;
		head->prev = n;
		head->prev->prev->next = n;
	}

}

void myLL::displayFromHead()
{
	if (head == nullptr)
		cout << "LL is empty" << endl;

	else
	{
		Node*temp = head;
		while (1)
		{
			cout << temp->data << endl;
			temp = temp->next;

			if (temp == head)
				break;
		}
	}
}