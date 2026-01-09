#include <iostream>
using namespace std;

template <class T>
class Array
{
protected:
	T *arr;
	int maxSize;
	int currentSize;
public:
	Array(int s);
	virtual void addValue(T value) = 0;
	virtual T removeValue() = 0;
	virtual bool isEmpty() = 0;
};

template <class T>
Array<T>::Array(int s)
{
	maxSize = s;
	currentSize = 0;
	arr = new T[s];
}