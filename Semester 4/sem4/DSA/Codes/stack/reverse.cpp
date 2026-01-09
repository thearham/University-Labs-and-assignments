#include "stack.h"

void insertAtBottom(Stack<int> &a, int element)
{
	if (a.isEmpty())
	{
		a.push(element);
		return;
	}
	int topElement = a.peak();
	a.pop();
	insertAtBottom(a, element);
	a.push(topElement);
}

void reverse(Stack<int>& a)
{
	if (a.isEmpty())
	{
		return;
	}
	int element = a.peak();
	a.pop();
	reverse(a);
	insertAtBottom(a, element);

}

int main() {
	Stack<int> a;
	a.push(10);
	a.push(20);
	a.push(30);

	reverse(a);
	while (!a.isEmpty())
	{
		cout << a.peak() << " ";
		a.pop();
	}
	cout << endl;
	return 0;
}