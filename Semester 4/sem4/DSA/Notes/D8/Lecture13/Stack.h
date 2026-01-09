#include "myLL.h"

class Stack
{
	myLL s;
public:
	void push(int value)
	{
		//s.insertAtTail(value);
		s.insertAtHead(value);
	}

	int pop()
	{
		//return s.deleteFromTail();

		return s.deleteFromHead();
	}

	void display()
	{
		s.display();
	}
};