//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* next;
//	Node(int data) {
//		this->data = data;
//		next = nullptr;
//	}
//};
//
//class LinkedList {
//private:
//	void printList(Node* current) {
//		if (current == nullptr) {
//			return;
//		}
//		else {
//			cout << "Data: " << current->data << endl;
//			printList(current->next);
//		}
//	}
//	void printListReverse(Node* current) {
//		if (current == nullptr) {
//			return;
//		}
//		else {
//			printListReverse(current->next);
//			cout << "Data: " << current->data << endl;
//		}
//	}
//public:
//	Node* head;
//	LinkedList() {
//		head = nullptr;
//	}
//
//	void insertNodeAtHead(int data) {
//		Node* newNode = new Node(data);
//		if (head == nullptr) {
//			head = newNode;
//		}
//		else {
//			newNode->next = head;
//			head = newNode;
//		}
//	}
//
//	void printList() {
//		printList(head);
//	}
//	void printListReverse() {
//		printListReverse(head);
//	}
//};
//
//int main() {
//	LinkedList list;
//	list.insertNodeAtHead(5);
//	list.insertNodeAtHead(4);
//	list.insertNodeAtHead(3);
//	list.insertNodeAtHead(2);
//	list.insertNodeAtHead(1);
//	list.printList();
//	cout << endl << endl;
//	list.printListReverse();
//
//	system("pause");
//}