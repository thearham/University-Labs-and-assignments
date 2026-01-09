#include<iostream>
#include<windows.h>
using namespace std;


class Link_list_Airports
{
	struct Node
	{
		string data;
		Node* next = nullptr;

		Node(string data)
		{
			this->data = data;
			next = NULL;
		}
	};
	Node* head = NULL;
public:
	Link_list_Airports()
	{
		head = nullptr;
	}
	void insert_data(string data)
	{
		Node* temp = head;
		Node* newNode = new Node(data);

		if (head == NULL)
		{
			head = newNode;
			return;
		}

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	string airportname;
	bool search(string x)
	{
		Node* current = head; // Initialize current
		while (current != NULL)
		{
			if (current->data == x)
			{
				airportname = current->data;
				return true;
			}
			current = current->next;
		}
		return false;
	}
	void display()
	{
		Node* temp = head;
		if (head == NULL)
		{
			cout << "\n List is Empty. \n";
		}
		while (temp != NULL)
		{
			cout << temp->data << " , ";
			temp = temp->next;

		}
		cout << endl;
	}

};


