#include <iostream>
using namespace std;

template <class T>
class Stack
{
protected:
	T *arr;
	int maxSize;
	int currentSize;
public:
	Stack(int s);
	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual T top() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
};

template <class T>
Stack<T>::Stack(int s)
{
	maxSize = s;
	currentSize = 0;
	arr = new T[s];
}