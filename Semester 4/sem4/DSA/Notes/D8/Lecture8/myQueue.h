#include "Queue.h"

template <class T>
class myQueue :public Queue<T>
{
	int rear;
	int front;
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
	cout << "Front Value = " << front << endl;
	cout << "Rear Value = " << rear << endl;
	for (int i = front; i < rear; i++)
		cout << i%maxSize << ". " << arr[i%maxSize] << endl;
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
		currentSize++;
		rear++;
	}

	else
		cout << "Queue is filled" << endl;
}


template <class T>
T myQueue<T>::dequeue() //O(1)
{
	if (isEmpty())
	{
		cout << "Queue in Empty";
		return NULL;			//this is different from: nullptr
	}

	currentSize--;
	return arr[front++%maxSize];



}