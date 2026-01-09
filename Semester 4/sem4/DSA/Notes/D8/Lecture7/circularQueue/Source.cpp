#include "myQueue.h"

int main()
{
	myQueue<int> q(4);

	q.enqueue(15);
	q.enqueue(-3);
	q.enqueue(0);
	q.enqueue(100);

	q.display(); 

	cout << endl << "Dequeued Value = " << q.dequeue() << endl << endl;

	q.display();

	q.enqueue(201);

	cout << endl << "Dequeued Value = " << q.dequeue() << endl << endl;

	//1 change in dequeue is required
	//display is required
	//STML = I won't rememeber.

	return 0;
}