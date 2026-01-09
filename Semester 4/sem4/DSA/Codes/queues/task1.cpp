#include <iostream>
using namespace std;

#define max 10

class Queue
{
private:
	int arr[max];
	int front, back;
public:
	Queue()
	{
		front = -1;
		back = -1;
	}

	void enqueue(int data)
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

	void dequeue()
	{
		if (front == -1 || front > back)
		{
			cout << "No elements in queue!\n";
			return;
		}
		front++;
	}

	int peek()
	{
		if (front == -1 || front > back)
		{
			cout << "No elements in queue!\n";
			return -1;
		}
		return arr[front];
	}

	bool empty()
	{
		if (front == -1 || front > back)
		{
			return true;
		}
		return false;
	}

};

int main()
{
	Queue q;

   q.Enqueue(10);
   q.Enqueue(20);
   q.Enqueue(30);

   q.Peek();

   q.Dequeue();
   q.Dequeue();

   q.Peek();

   q.Enqueue(40);
   q.Enqueue(50);

   q.Peek();

    return 0;
}
