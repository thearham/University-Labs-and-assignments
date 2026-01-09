#include "Node.h"
#include <iostream>
using namespace std;
template <class T>
class LinkedList
{
protected:
	Node<T> *head;
public:
	LinkedList();
	virtual void displayFromHead() = 0;
	virtual void insertSorted(T) = 0;
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
}