#include "Array.h"

template <class T>
class myArray :public Array<T>
{
public:
	void display();
	void addValue(T value);
	T removeValue();
	myArray(int);
	bool isEmpty();
};

template <class T>
bool myArray<T>::isEmpty()
{
	if (currentSize == 0)
	{
		cout << "Array in Empty" << endl;
		return true;

	}
		

	else
		return false;
}

template <class T>
T myArray<T>::removeValue()
{
	currentSize--;
	return arr[currentSize];
}

template <class T>
void myArray<T>::display()
{
	cout << "Max Size = " << maxSize << endl;
	cout << "Current Size = " << currentSize << endl;
	for (int i = 0; i < currentSize; i++)
		cout << i << ". " << arr[i] << endl;
}

template <class T>
myArray<T>::myArray(int s) :Array(s)
{

}

template <class T>
void myArray<T>::addValue(T value)
{
	arr[currentSize] = value;
	currentSize++;
}