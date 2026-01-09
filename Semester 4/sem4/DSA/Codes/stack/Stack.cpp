#include <iostream>
using namespace std;

// add, delete, search, display, sorting
class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = nullptr;
	}
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() {
		head = nullptr;
	}

	void push(int data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	void pop() {
		if (head == nullptr) {
			cout << "Nothing to delete!" << endl;
			return;
		}
		else {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void top() {
		if (head == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		else {
			cout << "Top: " << head->data;
			cout << endl;
		}
	}
};

int main() {
	LinkedList list;
	list.push(5);
	list.push(4);
	list.push(3);
	list.push(2);
	list.push(1);
	list.top();

	system("pause");
}