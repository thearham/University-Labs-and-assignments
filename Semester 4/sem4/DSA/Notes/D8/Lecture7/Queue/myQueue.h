#include "Queue.h"

template <class T>
class myQueue :public Queue<T>
{
public:
	void display();
	void enqueue(T value);
	T dequeue();
	T front();
	myQueue(int);
	bool isEmpty();
	bool isFull();
};

template <class T>
bool myQueue<T>::isFull()
{
	/*if (maxSize == currentSize)
		return true;

	else
		return false;
		*/

	return Queue<T>::maxSize == Queue<T>::currentSize;
}

template <class T>
bool myQueue<T>::isEmpty()
{
	if (Queue<T>::currentSize == 0)
	{
		cout << "Queue in Empty" << endl;
		return true;

	}
		

	else
		return false;
}

template <class T>
T myQueue<T>::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue in Empty";
		return NULL;			//this is different from: nullptr
	}

	T temp = arr[0];
	currentSize--;

	for (int i = 0; i < currentSize; i++)
		arr[i] = arr[i + 1];

	return temp;
}

template <class T>
T myQueue<T>::front()
{
	if (isEmpty())
	{
		cout << "Queue in Empty";
		return NULL;			//this is different from: nullptr
	}

	return Queue<T>::arr[0];
}

template <class T>
void myQueue<T>::display()
{
	cout << "Max Size = " << Queue<T>::maxSize << endl;
	cout << "Current Size = " << Queue<T>::currentSize << endl;
	for (int i = 0; i < Queue<T>::currentSize; i++)
		cout << i << ". " << Queue<T>::arr[i] << endl;
}

template <class T>
myQueue<T>::myQueue(int s) :Queue<T>(s)
{

}

template <class T>
void myQueue<T>::enqueue(T value)
{
	if (!isFull())
	{
		Queue<T>::arr[Queue<T>::currentSize] = value;
		Queue<T>::currentSize++;
	}

	else
		cout << "Queue is filled" << endl;
}