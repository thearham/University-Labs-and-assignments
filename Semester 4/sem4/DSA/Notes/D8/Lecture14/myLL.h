#include "LinkedList.h"

class myLL :public LinkedList
{
	
	void insertAtTail(int value);
public:
	void insertAtHead(int value);
	void insertSorted(int value);
	void display();
	int deleteFromHead();
	int deleteFromTail();

	void insertLastNode(int value);
	
};

void myLL::insertLastNode(int value)
{
	if (head == nullptr)
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;
		head = newNode;
	}


	else
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;

		Node *t = head;

		while (t->next != nullptr)
		{
			t = t->next;
		}

		t->next = newNode;
	}
}

void myLL::insertSorted(int value)
{
	if (head == nullptr)
	{
		Node* nn = new Node;
		nn->next = nullptr;
		nn->data = value;
		head = nn;
	}
	else if (value <= head->data)
		insertAtHead(value);

}

int myLL::deleteFromTail()
{
	if (head == nullptr)
	{
		cout << "LL empty" << endl;
		return NULL;
	}

	else if (head->next == nullptr) //single node case
	{
		int rv = head->data;
		delete head;
		head = nullptr;
		return rv;
	}

	else //non-empty LL
	{
		
		Node* t = head;

		while (1)
		{
			if (t->next->next == nullptr)
				break;

			t = t->next;
		}
		int rv = t->next->data;
		delete t->next;
		t->next = nullptr;
		return rv;
	}
}


void myLL::insertAtTail(int value)
{
	Node* nn = new Node;
	nn->next = nullptr;
	nn->data = value;

	if (head == nullptr)
		head = nn;

	else
	{
		Node* t = head;

		while (1)
		{
			if (t->next == nullptr)
				break;

			t = t->next;
		}

		t->next = nn;

	}
}


int myLL::deleteFromHead()
{
	if (head == nullptr)
	{
		cout << "LL empty" << endl;
		return NULL;
	}

	else if (head->next == nullptr) //single node case
	{
		int rv = head->data;
		delete head;
		head = nullptr;
		return rv;
	}

	else //non-empty LL
	{
		int rv = head->data;
		Node* t = head;
		head = head->next;
		delete t;
		t = nullptr;
		return rv;
	}
}

void myLL::insertAtHead(int value)
{
	Node* nn = new Node;
	nn->next = nullptr;
	nn->data = value;

	if (head == nullptr)
		head = nn;
	
	else
	{
		nn->next = head;
		head = nn;
	}
}

void myLL::display()
{
	if (head == nullptr)
		cout << "LL is empty" << endl;

	else
	{
		Node* t = head;

		while (1)
		{
			cout << t->data << endl;
			t = t->next;

			if (t == nullptr)
				break;
		}
	}
}

