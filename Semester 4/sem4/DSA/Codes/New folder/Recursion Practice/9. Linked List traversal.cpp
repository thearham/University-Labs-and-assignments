//#include <iostream>
//using namespace std;
//
//class Node {
//private:
//
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
//public:
//	Node* head;
//	LinkedList() {
//		head = nullptr;
//	}
//
//	Node *traverseLinkedListRecursive(Node* current) {
//		if (current->next == nullptr) {
//			return current;
//		}
//		traverseLinkedListRecursive(current->next);
//	}
//
//	void addNode(int data) {
//		Node* newNode = new Node(data);
//		if (head == nullptr) {
//			head = newNode;
//		}
//		else {
//			newNode->next = head;
//			head = newNode;
//		}
//	}
//};
//
//int main() {
//	LinkedList list;
//	list.addNode(3);
//	list.addNode(2);
//	list.addNode(1);
//	cout << list.traverseLinkedListRecursive(list.head)->data;
//	system("pause");
//}