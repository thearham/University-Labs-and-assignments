#include "myStack.h"

int main()
{
	myStack<char> a1(3);

	a1.push('A');
	a1.push('S');
	a1.push('D');
	a1.push('F');

	a1.display();

	cout << endl <<  "Top Value = " << a1.top() << endl << endl;

	a1.display();

	return 0;
}