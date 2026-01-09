#include "myLL.h"

int main()
{
	
	Node a;
	a.data = 15;
	a.next = nullptr;
	Node* h;

	{
		Node *a = new Node;
		a->data = 15;
		a->next = nullptr;
		a->data = 25;

		a->data = 1024;
		h = a;
		delete a;
	}

	cout << a.data << endl;
	cout << h->data << endl;

	return 0;
}