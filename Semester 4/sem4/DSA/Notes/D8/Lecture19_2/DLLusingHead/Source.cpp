#include "myLL.h"

int main()
{
	myLL<int> obj;
	
	obj.insertSorted(15);
	obj.insertSorted(10);
	obj.insertSorted(-3);
	obj.insertSorted(12);
	obj.insertSorted(999);

	cout << "Display From Head = " << endl;
	obj.displayFromHead();

	return 0;
}