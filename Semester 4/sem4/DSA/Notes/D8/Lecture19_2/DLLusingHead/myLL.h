#include "LinkedList.h"

template <class T>
class myLL:public LinkedList<T>
{
public:
	void displayFromHead();
	void insertSorted(T);

};

template <class T>
void myLL<T>::insertSorted(T value)
{
	if (head == nullptr)
	{
		Node<T>*nn = new Node<T>;
		nn->next = nullptr;
		nn->prev = nullptr;
		nn->data = value;

		head = nn;
	}

	else if (value <= head->data)
	{
		Node<T>*nn = new Node<T>;
		nn->next = nullptr;
		nn->prev = nullptr;
		nn->data = value;

		nn->next = head;
		head->prev = nn;
		head = head->prev; //head = nn;
	}

	else
	{
		Node<T>*nn = new Node<T>;
		nn->next = nullptr;
		nn->prev = nullptr;
		nn->data = value;

		Node<T>*p = head;

		while (1)
		{
			if (p->data < value && p->next->data >= value)
			{
				nn->next = p->next;
				nn->prev = p;
				p->next->prev = nn;
				p->next = nn;
				break;
			}

			p = p->next;

			if (p->next == nullptr) //you are at last node
			{
				nn->prev = p;
				p->next = nn;
				break;
			}
		}
	}

}



template <class T>
void myLL<T>::displayFromHead()
{
	if (head == nullptr)
		cout << "LL is empty" << endl;

	else
	{
		Node<T> *temp = head;
		while (1)
		{
			cout << temp->data << endl;
			temp = temp->next;

			if (temp == nullptr)
				break;
		}

	}
}
