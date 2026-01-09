#include "Queue.h"

template <class T>
class myQueue :public Queue<T>
{
	int front;
	int rear;
public:
	void display();
	void enqueue(T value);
	T dequeue();
	T frontValue();
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

	currentSize--;
	return arr[front++];
}

template <class T>
T myQueue<T>::frontValue()
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
	cout << "Front = " << front << endl;
	cout << "Rear = " << rear << endl;
	//for (int i = 0; i < (rear-front); i++)
	//	cout << i << ". " << Queue<T>::arr[i] << endl;
}

template <class T>
myQueue<T>::myQueue(int s) :Queue<T>(s)
{
	front = 0;
	rear = 0;
}

template <class T>
void myQueue<T>::enqueue(T value)
{
	if (!isFull())
	{
		arr[rear%maxSize] = value;
		rear++;
		currentSize++;
	}

	else
		cout << "Queue is filled" << endl;
}