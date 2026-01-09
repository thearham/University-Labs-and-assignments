#include "myLL.h"

int main()
{
	myLL obj;
	obj.insertAtTail(15);
	obj.insertAtTail(-3);
	obj.insertAtTail(20);
	obj.insertAtTail(50);
	obj.insertAtHead(10);

	cout << "Delete from Tail: " << obj.deleteFromTail() << endl;

	obj.display();
	return 0;
}