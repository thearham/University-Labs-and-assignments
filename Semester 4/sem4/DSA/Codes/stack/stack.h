#pragma once
#include <iostream>
#include <string>
using namespace std;
#define max 100

template <class T>
class Stack
{
private:
	T arr[max] = {};
	int top;
public:
	Stack() : top(-1) {}
	bool isFull()
	{
		if (top == max - 1)
		{
			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		return false;
	}
	void push(T a)
	{
		if (!isFull())
		{
			top++;
			arr[top] = a;
		}
		else
		{
			cout << "Stack overflow" << endl;
		}

	}
	void pop()
	{
		if (!isEmpty())
		{
			top--;
		}
		else
		{
			cout << "Stack empty" << endl;
		}
	}
	T peak()
	{
		if (!isEmpty())
		{
			return arr[top];
		}
		return NULL;
	}
};