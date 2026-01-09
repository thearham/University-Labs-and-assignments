#include<iostream>
using namespace std;



class node {
public:
    node* prev;
    string data;
    node* next;

    node(string value) {  // A constructor is called here
        prev = NULL;      // By default previous pointer is pointed to NULL
        data = value;   // value is assigned to the data
        next = NULL;   
                        // By default next pointer is pointed to NULL
    }
};
class DoublyList
{
public:
    void insert_at_head(node*& head, string value) {

        node* n = new node(value);
        n->next = head;

        if (head != NULL) {
            head->prev = n;
        }

        head = n;
    }


    void insert_at_tail(node*& head, string value) {

        if (head == NULL) {
            insert_at_head(head, value);
            return;
        }

        node* n = new node(value);
        node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }



    node* removeLastNode(struct node* head)
    {
        if (head == NULL)
            return NULL;

        if (head->next == NULL) {
            delete head;
            return NULL;
        }

        // Find the second last node
        node* second_last = head;
        while (second_last->next->next != NULL)
            second_last = second_last->next;

        // Delete last node
        delete (second_last->next);

        // Change next of second last
        second_last->next = NULL;

        return head;
    }


    void display(node* head) {
        int i = 0;
        node* temp = head;
        while (temp != NULL) {
            i++;
            cout << "\n Passenger at seat No. "<< i <<" : " << temp->data ;
            temp = temp->next;
        }
    }
};


class node1 {
public:
    node1* prev1;
    int data1;
    node1* next1;

    node1(int value) {  // A constructor is called here
        prev1 = NULL;      // By default previous pointer is pointed to NULL
        data1 = value;   // value is assigned to the data
        next1 = NULL;
        // By default next pointer is pointed to NULL
    }
};
class DoublyList1
{
public:
    void insert_at_head_flight(node1*& head1, int value) {

        node1* n = new node1(value);
        n->next1 = head1;

        if (head1 != NULL) {
            head1->prev1 = n;
        }

        head1 = n;
    }


    void insert_at_tail_flight(node1*& head1, int value) {

        if (head1 == NULL) {
            insert_at_head_flight(head1, value);
            return;
        }

        node1* n = new node1(value);
        node1* temp = head1;

        while (temp->next1 != NULL) {
            temp = temp->next1;
        }
        temp->next1 = n;
        n->prev1 = temp;
    }



    node1* removeLastNode_flight(struct node1* head1)
    {
        if (head1 == NULL)
            return NULL;

        if (head1->next1 == NULL) {
            delete head1;
            return NULL;
        }

        // Find the second last node
        node1* second_last = head1;
        while (second_last->next1->next1 != NULL)
            second_last = second_last->next1;

        // Delete last node
        delete (second_last->next1);

        // Change next of second last
        second_last->next1 = NULL;

        return head1;
    }


    void display_flight(node1* head1) {
        int i = 0;
        node1* temp = head1;
        while (temp != NULL) {
            i++;
            cout << "\n Passenger  at seat No. " << i << " : has flight no " << temp->data1;
            temp = temp->next1;
        }
    }
};



