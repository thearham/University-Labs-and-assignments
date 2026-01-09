#include "mLL.h"

int main()
{
	myLL obj;
	obj.insertAtHead(-3);
	obj.insertAtHead(20);
	obj.insertAtHead(15);
	obj.insertAtHead(40);

	cout << "Delete From Tail = " << obj.deleteFromTail() << endl;

	cout << "Display = " << endl;
	obj.displayFromHead();
	return 0;
}