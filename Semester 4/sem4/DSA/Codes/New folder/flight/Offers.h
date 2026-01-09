#include<iostream>
using namespace std;
class Array
{
	int current_size = 0;
	int maximum_size = 0;
	char* arr;
public:
	Array()
	{
		arr = nullptr;
		current_size = 0;
		maximum_size = 0;
	}
    void insert(char*arr,int maxsize)
	{
		maximum_size = maxsize;
		this->arr = new char [current_size];
		int size = 0;
		for ( size = 0; arr[size]!='\0'; size++);
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = arr[i];
			current_size++;
		}
		this->arr[size] = '\0';
	}
	void Display()
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << arr[i];
		}
	}

};
