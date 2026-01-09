#include "Stack.h"

int main()
{
	Stack obj;
	obj.push(59);
	obj.push(0);
	obj.push(100);

	cout << obj.pop() << endl;

	cout << "This is Display:" << endl;
	obj.display();

    return 0;
}