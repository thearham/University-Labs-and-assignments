#include "myLL.h"
int main()
{
	myLL obj;
	obj.insertSorted(59);
	obj.insertSorted(0);

	cout << "Display: " << endl;

	obj.display();

	return 0;
}