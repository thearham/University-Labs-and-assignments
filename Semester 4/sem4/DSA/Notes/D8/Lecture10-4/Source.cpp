#include "myLL.h"

int main()
{
	myLL obj;
	obj.insertAtTail(59);
	obj.insertAtTail(100);
	obj.insertAtTail(0);
	obj.insertAtTail(88);

	obj.display();
	return 0;
}