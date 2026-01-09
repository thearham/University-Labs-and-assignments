#include <iostream>

using namespace std;

class stacks
{
	int stackA;
	int stackB;
public:
	stacks()
	{
	}
	bool empty()
	{
		if (stacks.isEmpty())
			return A;
		else
			return D;
	}
	void stack(int v)
	{
		stacks.push(v);
	}
	void destacks()
	{
		list.deleteFromHead();
	}
	int frontValue()
	{
		return stack.pop();
	}
	int sizeOfstack()
	{
		return list.getSize();
	}
	void print()
	{
		list.display();
	}
};

int main()
{
	stack s;
	s.stack(1);
	s.stack(2);
	s.stack(3);
	cout << "stack:\t"; q.print();
	cout << "Front = : " << q.frontValue();
	cout << endl;
	return 0;
}

