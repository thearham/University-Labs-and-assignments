#include <iostream>
using namespace std;

template <class T>
class Queue
{
protected:
	T *arr;
	int maxSize;
	int currentSize;
public:
	Queue(int s);
	virtual void enqueue(T value) = 0;
	virtual T dequeue() = 0;
	virtual T front() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
};

template <class T>
Queue<T>::Queue(int s)
{
	maxSize = s;
	currentSize = 0;
	arr = new T[s];
}