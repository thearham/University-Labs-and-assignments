#include <iostream>
using namespace std;

// add, delete, search, display, sorting
class Node{
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
	void reverse_display(Node* temp) {
		if (temp == nullptr) {
			return;
		}
		reverse_display(temp->next);
		cout << "Data: " << temp->data << endl;
	}

public:
	LinkedList() {
		head = nullptr;
	}

	void add_to_head(int data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	void add_to_specific_location(int data, int location) {
		if (location < 1) {
			cout << "Invalid location!" << endl;
			return;
		}
		else if (location == 1) {
			add_to_head(data);
		}
		else {
			Node* newNode = new Node(data);
			Node* temp = head;
			for (int i = 1; i < location - 1; i++) {
				if (temp->next == nullptr) {
					cout << "Location doesnt exist!" << endl;
					return;
				}
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}

	void add_to_tail(int data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}

	}

	void delete_from_head() {
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

	void delete_from_specific_location(int location) {
		if (location < 1) {
			cout << "Invalid Location!" << endl;
			return;
		}
		else if (location == 1) {
			delete_from_head();
		}
		else {
			Node* temp = head;
			for (int i = 1; i < location - 1; i++) {
				if (temp->next == nullptr) {
					cout << "Location exceeds list size!" << endl;
					return;
				}
				temp = temp->next;
			}
			Node* nodeToDelete = temp->next;
			temp->next = temp->next->next;
			delete nodeToDelete;
		}
	}

	void delete_from_tail() {
		if (head == nullptr) {
			cout << "Nothing to delete!" << endl;
			return;
		}
		else {
			Node* previous = nullptr;
			Node* temp = head;
			while (temp->next != nullptr) {
				previous = temp;
				temp = temp->next;
			}
			delete temp;
			previous->next = nullptr;
		}
	}
	
	void searching(int key) {
		if (head == nullptr) {
			cout << "List is empty!" << endl;
			return;
		}
		else {
			Node* temp = head;
			int count = 0;
			bool check = false;
			while (temp->next != nullptr) {
				count++;
				if (temp->data == key) {
					check = true;
					break;
				}
				temp = temp->next;
			}

			if (check == true) {
				cout << key << " found at position " << count << endl;
			}
			else {
				cout << key << " Not found in list "<< endl;
			}
		}
	}

	void reverse_display() {
		reverse_display(head);
	}

	void display() {
		Node* temp = head;
		while (temp != nullptr) {
			cout << "Address: " << temp << endl;
			cout << "Data: " << temp->data << endl;
			cout << "Next: " << temp->next << endl;
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	LinkedList list;
	list.add_to_head(2);
	list.add_to_head(1);
	list.add_to_tail(3);
	list.add_to_tail(4);
	list.add_to_tail(5);
	list.display();
	cout << endl << endl;
	list.reverse_display();


	system("pause");
}