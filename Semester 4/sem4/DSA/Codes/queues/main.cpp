#include "queue.h"

int main()
{
	Queue q;
	q.enqueue(40);
	q.enqueue(20);
	q.enqueue(30);
	cout << q.peek() << endl;
	q.dequeue();
	cout << q.peek() << endl;

	return 0;
}