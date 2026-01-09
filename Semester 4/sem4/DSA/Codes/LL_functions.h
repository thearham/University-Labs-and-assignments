#pragma once
#include "LinkedList.h"

void insert_at_tail(Node*& head, int x)
{
	Node* n = new Node(x);

	if (head == NULL)
	{
		head = n;
		return;
	}

	Node* temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
}

void insert_at_head(Node*& head, int x)
{
	Node* n = new Node(x);
	n->next = head;
	head = n;
}

bool search(Node* head, int key)
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			return true;
		}
		temp = temp->next;
	}
	return 0;
}

void delete_at_head(Node*& head)
{
	Node* toDelete = head;
	head = head->next;
	delete toDelete;
}

void deletion(Node*& head, int key)
{
	if (head == NULL)
	{
		return;
	}
	if (head->next == NULL)
	{
		delete_at_head(head);
		return;
	}
	if (head->data == key)
	{
		delete_at_head(head);
		return;
	}
	Node* temp = head;
	while (temp->next->data != key)
	{
		temp = temp->next;
	}
	Node* toDelete = temp->next;
	temp->next = temp->next->next;
	delete toDelete;
}

void display(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << "->";
		temp = temp->next;
	}
	std::cout << "NULL \n";
}

Node* reverse_list(Node*& head)
{
	Node* prev = NULL;
	Node* curr = head;
	Node* next;

	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

Node* reverse_list_k_nodes(Node*& head, int k)
{
	Node* prev = NULL;
	Node* curr = head;
	Node* next{};
	int count = 0;

	while (curr != NULL && count < k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if (next != NULL)
	{
		head->next = reverse_list_k_nodes(next, k);
	}
	return prev;
}

int length(Node*& head)
{
	Node* temp = head;
	int count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

Node* k_append(Node*& head, int k)
{
	Node* newHead{};
	Node* newTail = head;
	Node* tail = head;
	int len = length(head);
	k = k % len;
	int count = 1;

	while (tail->next != NULL)
	{
		if (count == len - k)
		{
			newTail = tail;
		}
		if (count == len - k + 1)
		{
			newHead = tail;
		}
		tail = tail->next;
		count++;
	}
	newTail->next = NULL;
	tail->next = head;
	return newHead;
}
bool detectCycle(Node*& head)
{
	Node* slow = head;
	Node* fast = head;

	while (fast != NULL and fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}

void makeCycle(Node*& head, int pos)
{
	Node* temp = head;
	Node* startNode{};
	int count = 1;

	while (temp->next != NULL)
	{
		if (count == pos)
		{
			startNode = temp;
		}
		temp = temp->next;
		count++;
	}
	temp->next = startNode;
}

void removeCycle(Node*& head)
{
	Node* slow = head;
	Node* fast = head;

	do
	{
		slow = slow->next;
		fast = fast->next->next;

	} while (slow != fast);

	fast = head;

	while (slow->next != fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = NULL;
}

void makeIntersection(Node*& head1, Node*& head2, int pos)
{
	Node* temp1 = head1;
	pos--;
	while (pos--)
	{
		temp1 = temp1->next;
	}
	Node* temp2 = head2;

	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp1;
}

int intersection_at(Node*& head1, Node*& head2)
{
	int l1 = length(head1);
	int l2 = length(head2);

	int d = 0;
	Node* ptr1 = head1;
	Node* ptr2 = head2;

	if (l1 > l2)
	{
		d = l1 - l2;
		ptr1 = head1;
		ptr2 = head2;
	}
	else
	{
		d = l2 - l1;
		ptr1 = head2;
		ptr2 = head1;
	}
	while (d)
	{
		ptr1 = ptr1->next;
		if (ptr1->next == NULL)
		{
			return -1;
		}
		d--;
	}
	while (ptr1 != NULL and ptr2 != NULL)
	{
		if (ptr1 == ptr2)
		{
			return ptr1->data;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return -1;
}

Node* merge(Node*& head1, Node*& head2)
{
	Node* p1 = head1;
	Node* p2 = head2;
	Node* dummyNode = new Node(-1);
	Node* p3 = dummyNode;

	while (p1 != NULL and p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			p3->next = p1;
			p1 = p1->next;
		}
		else
		{
			p3->next = p2;
			p2 = p2->next;
		}
		p3 = p3->next;
	}

	while (p1 != NULL)
	{
		p3->next = p1;
		p1 = p1->next;
		p3 = p3->next;
	}
	while (p2 != NULL)
	{
		p3->next = p2;
		p2 = p2->next;
		p3 = p3->next;
	}
	return dummyNode->next;
}