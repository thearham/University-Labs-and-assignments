#include "myQueue.h"

int main()
{
	myQueue<int> q(4);

	q.enqueue(15);
	q.enqueue(-3);
	q.enqueue(0);

	q.display(); 

	cout << endl << "Dequeued Value = " << q.dequeue() << endl << endl;

	q.display();

	return 0;
}