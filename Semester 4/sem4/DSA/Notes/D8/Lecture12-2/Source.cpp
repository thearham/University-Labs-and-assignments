#include "myLL.h"

int main()
{
    myLL obj;

	obj.insertAtTail(59);
	obj.insertAtHead(99);
	obj.insertAtHead(-30);
	obj.insertAtTail(555);

	cout << "Deleted Value is: " << obj.deleteFromTail() << endl;
    
    cout << "This is Display Function: " << endl;
    obj.display();

    return 0;
}