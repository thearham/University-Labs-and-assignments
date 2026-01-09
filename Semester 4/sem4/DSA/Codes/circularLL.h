#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int x) : data(x), next(NULL) {}
};

void insertAtheadC(Node*& head, int x)
{
	Node* newNode = new Node(x);
	if (head == NULL)
	{
		newNode->next = newNode;
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != head)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->next = head;
	head = newNode;
}
void insertAtTailC(Node*& head, int x)
{
	Node* newNode = new Node(x);
	if (head == NULL)
	{
		insertAtheadC(head, x);
		return;
	}
	Node* temp = head;
	while (temp->next != head)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->next = head;
}

void DisplayC(Node*& head)
{
	Node* temp = head;

	do
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	} while (temp != head);
}