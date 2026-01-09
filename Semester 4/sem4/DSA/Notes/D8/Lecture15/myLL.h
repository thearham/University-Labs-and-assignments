#include "LinkedList.h"
class myLL:public LinkedList
{
public:
    void insertAtTail(int value);
    void display();
    void insertAtHead(int value);
    int deleteFromHead();
	int deleteFromTail();
	void insertSorted(int value);
	bool deleteValue(int value);
};

bool myLL::deleteValue(int value)
{
	if (head == nullptr && tail == nullptr)
		return false; 

	else if (head == tail)
	{
		if (head->data == value)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return true;
		}

		return false;
	}

	else if (value == head->data)
	{
		deleteFromHead();
		return true;
	}

	else if (value == tail->data)
	{
		deleteFromTail();
		return true;
	}

	else
	{
		Node*d = head->next;
		Node*p = head;

		while (1)
		{
			if (value == d->data)
				break;

			p = d;
			d = d->next;

			if (d == tail)
				return false;
		}

		p->next = d->next;
		delete d;
		d = nullptr;
		return true;
	}
}

void myLL::insertSorted(int value)
{
	if (head == nullptr && tail == nullptr) //LL is empty
	{
		Node*nn = new Node;
		nn->data = value;
		nn->next = nullptr;
		head = nn;
		tail = nn;
	}

	else if (value <= head->data)	//smallest value
		insertAtHead(value);

	else if (value >= tail->data)	//largest value
		insertAtTail(value);

	else //in between
	{
		Node*nn = new Node;
		nn->data = value;
		nn->next = nullptr;

		Node*temp = head;

		while (1)
		{
			if (temp->data < value && temp->next->data >= value)
				break;

			temp = temp->next;
		}

		nn->next = temp->next;
		temp->next = nn;
	}
}

int myLL::deleteFromTail()
{
	if (head == nullptr && tail == nullptr) //LL is empty
	{
		cout << "LL is empty" << endl;
		return NULL;
	}

	//single node case
	else if (head == tail)
	{
		Node* temp = head;
		head = head->next;
		int returnValue = temp->data;
		delete temp;
		temp = nullptr;
		tail = nullptr;
		head = nullptr;
		return returnValue;
	}

	else
	{
		Node*temp = head;

		while (true)
		{
			if (temp->next == tail)
				break;

			temp = temp->next;
		}

		int rV = tail->data;
		delete tail;
		tail = temp;
		temp->next = nullptr;
		return rV;
	}


}



int myLL::deleteFromHead() 
{
    if (head == nullptr && tail == nullptr) //LL is empty
    {
        cout << "LL is empty" << endl;
        return NULL;
    }

    //single node case
    else if (head == tail)
    {
        Node*temp = head;
        head = head->next;
        int returnValue = temp->data;
        delete temp;
        temp = nullptr;
        tail = nullptr;
        head = nullptr;
        return returnValue;
    }

    else //LL is not empty   
    {
        Node*temp = head;
        head = head->next;
        int returnValue = temp->data;
        delete temp;
        temp = nullptr;
        return returnValue;
    }
    
}

void myLL::insertAtHead(int value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->next = nullptr;

    if (head == nullptr && tail == nullptr) //LL is empty
    {
        head = nn;
        tail = nn;
    }

    else //non-empty LL
    {
       nn->next = head;
       head = nn;
    }
}

void myLL::display()
{

    if (head == nullptr && tail == nullptr)
        cout << "LL is empty" << endl;
    
    else 
    {
        Node*temp = head;

        while(1)
        {
            cout << temp->data << endl;
            temp = temp->next;

            if (temp == nullptr)
            break;
        }
    }
    
}

void myLL::insertAtTail(int value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->next = nullptr;

    if (head == nullptr && tail == nullptr) //LL is empty
    {
        head = nn;
        tail = nn;
    }

    else // when LL is not EMPTY
    {
        tail->next = nn;
        tail = nn;
    }
}