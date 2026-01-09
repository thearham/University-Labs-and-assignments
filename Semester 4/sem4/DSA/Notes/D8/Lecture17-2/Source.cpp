#include "myLL.h"

int main()
{
	
	myLL obj;

	obj.insertAtTail(10);
	obj.insertAtTail(966);
	obj.insertAtTail(477);
	obj.insertAtTail(13);


	cout << "Deleted Value = " << obj.deleteValue(45) << endl;

	cout << "Display: " << endl;
	
	obj.display();


	return 0;
}