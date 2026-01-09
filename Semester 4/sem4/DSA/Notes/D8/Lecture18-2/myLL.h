#pragma once
#include "LinkedList.h"
class myLL :public LinkedList
{
public:
	void insertAtTail(int);
	void insertAtHead(int);
	void display();
	int deleteFromTail();
};

int myLL::deleteFromTail()
{
	if (tail == nullptr)
		return NULL;

	else if (tail->next == tail) //single node
	{
		int rV = tail->data;
		delete tail;
		tail = nullptr;
		return rV;
	}

	else
	{
		Node* temp = tail->next;

		while (1)
		{
			if (temp->next == tail)
				break;

			temp = temp->next;
		}

		int rV = tail->data;
		temp->next = tail->next;
		delete tail;
		tail = temp;
		return rV;
	}
}

void myLL::display()
{
	if (tail == nullptr) //LL is empty
		cout << "LL is empty" << endl;

	else
	{
		Node* temp = tail->next;

		while (1)
		{
			cout << temp->data << endl;
			temp = temp->next;

			if (temp == tail->next)
				break;

			
		}
	}
}

void myLL::insertAtTail(int value)
{
	if (tail == nullptr)
	{
		Node* nn = new Node;
		nn->data = value;
		nn->next = nullptr;

		tail = nn;
		tail->next = tail; 
		// nn->next = nn; 
		// nn->next = tail; 
		// tail->next = nn;
	}

	else
	{
		Node* nn = new Node;
		nn->data = value;
		nn->next = nullptr;

		nn->next = tail->next;
		tail->next = nn;
		tail = nn; //tail = tail->next;
	}
}


void myLL::insertAtHead(int value)
{
	if (tail == nullptr)
	{
		Node* nn = new Node;
		nn->data = value;
		nn->next = nullptr;

		tail = nn;
		tail->next = tail;
		// nn->next = nn; 
		// nn->next = tail; 
		// tail->next = nn;
	}

	else
	{
		Node* nn = new Node;
		nn->data = value;
		nn->next = nullptr;

		nn->next = tail->next;
		tail->next = nn;
	}
}

