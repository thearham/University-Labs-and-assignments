#pragma once
#include <iostream>
using namespace std;

#define max 10

class Queue
{
public:
	Queue();
	~Queue();
	void enqueue(int data);
	void dequeue();
	int peek();
	bool empty();

private:
	int* arr;
	int front, back;
};

Queue::Queue()
{
	arr = new int[max];
	front = -1;
	back = -1;
}

void Queue::enqueue(int data)
{
	if (back == max - 1)
	{
		cout << "Queue is Overflowing!\n";
		return;
	}
	back++;
	arr[back] = data;
	if (front == -1)
	{
		front++;
	}
}

void Queue::dequeue()
{
	if (front == -1 || front > back)
	{
		cout << "No elements in queue!\n";
		return;
	}
	front++;
}

int Queue::peek()
{
	if (front == -1 || front > back)
	{
		cout << "No elements in queue!\n";
		return -1;
	}
	return arr[front];
}

bool Queue::empty()
{
	if (front == -1 || front > back)
	{
		return true;
	}
	return false;
}

Queue::~Queue()
{
	delete[] arr;
}