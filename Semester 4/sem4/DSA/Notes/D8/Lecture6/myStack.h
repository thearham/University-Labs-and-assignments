#include "Stack.h"

template <class T>
class myStack :public Stack<T>
{
public:
	void display();
	void push(T value);
	T pop();
	T top();
	myStack(int);
	bool isEmpty();
	bool isFull();
};

template <class T>
bool myStack<T>::isFull()
{
	/*if (maxSize == currentSize)
		return true;

	else
		return false;
		*/

	return Stack<T>::maxSize == Stack<T>::currentSize;
}

template <class T>
bool myStack<T>::isEmpty()
{
	if (Stack<T>::currentSize == 0)
	{
		cout << "Stack in Empty" << endl;
		return true;

	}
		

	else
		return false;
}

template <class T>
T myStack<T>::pop()
{
	if (isEmpty())
	{
		cout << "Stack in Empty";
		return NULL;			//this is different from: nullptr
	}

	Stack<T>::currentSize--;
	return Stack<T>::arr[Stack<T>::currentSize];
}

template <class T>
T myStack<T>::top()
{
	if (isEmpty())
	{
		cout << "Stack in Empty";
		return NULL;			//this is different from: nullptr
	}

	return Stack<T>::arr[Stack<T>::currentSize - 1];
}

template <class T>
void myStack<T>::display()
{
	cout << "Max Size = " << Stack<T>::maxSize << endl;
	cout << "Current Size = " << Stack<T>::currentSize << endl;
	for (int i = 0; i < Stack<T>::currentSize; i++)
		cout << i << ". " << Stack<T>::arr[i] << endl;
}

template <class T>
myStack<T>::myStack(int s) :Stack<T>(s)
{

}

template <class T>
void myStack<T>::push(T value)
{
	if (!isFull())
	{
		Stack<T>::arr[Stack<T>::currentSize] = value;
		Stack<T>::currentSize++;
	}

	else
		cout << "Stack is filled" << endl;
}