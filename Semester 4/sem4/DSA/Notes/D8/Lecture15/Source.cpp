#include "myLL.h"

int main()
{
   
	myLL a;

	a.insertAtHead(-3);
	a.insertAtTail(100);
	a.insertAtTail(50);
	a.insertAtTail(77);
	a.insertAtTail(0);

	cout << "Delete Value = " << a.deleteValue(999) << endl;

    cout << "This is Display Function: " << endl;
    a.display();

    return 0;
}