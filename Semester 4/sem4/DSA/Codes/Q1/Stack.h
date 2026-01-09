#pragma once
#include <iostream>
using namespace std;
class stack {
private:
	static const int max = 16;  
	int top;
	int array[max][2];
public:
	stack();
	void push(int row, int column);
	void pop();
	int toprow();
	int topcolumn();
	bool empty();
	~stack();
};


stack::stack() {
	top = 0;
}

void stack::push(int row, int column) {
	if (top< max - 1) {
		top++;
		array[top][0] = row;
		array[top][1] = column;
		
	}
}

void stack::pop() {
	if (!empty())
	{
		--top;
	}
	else
		cout << "Stack is empty " << endl;
}
int stack::toprow() {
	if (!empty()) {
		return array[top][0];
	}
	else {
		cout << "Stack is empty " << endl;
		return 0;
	}
}
int stack::topcolumn() {
	if (!empty()) {
		return array[top][1];
	}
	else {
		cout << "Stack is empty " << endl;
		return 0;
	}
}

bool stack::empty() {
	if (top == 0)
	{
		return true;
	}
	else
		return false;
}
stack::~stack()
{
	
}