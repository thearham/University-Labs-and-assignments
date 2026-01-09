#include "myQueue.h"

int main()
{
	myQueue<int> q(3);

	q.enqueue(15);
	q.enqueue(-3);
	cout << endl << "Dequeued Value = " << q.dequeue() << endl << endl;
	q.enqueue(0);
	q.enqueue(18);
	cout << endl << "Dequeued Value = " << q.dequeue() << endl << endl;
	q.enqueue(19);
	cout << endl << "Dequeued Value = " << q.dequeue() << endl << endl;
	cout << endl << "Dequeued Value = " << q.dequeue() << endl << endl;
	q.display();



	

	

//	

//	q.display();

	return 0;
}