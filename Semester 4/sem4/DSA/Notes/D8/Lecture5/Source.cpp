#include "myStack.h"

int main()
{
	myStack<char> a1(3);

	a1.addValue('A');
	a1.addValue('S');
	a1.addValue('D');
	a1.addValue('F');

	a1.display();

	return 0;
}