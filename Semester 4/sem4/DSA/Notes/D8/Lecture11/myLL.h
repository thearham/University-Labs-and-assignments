#include "LinkedList.h"
class myLL:public LinkedList
{
public:
    void insertAtTail(int value);
    void display();
    void insertAtHead(int value);
    int deleteFromHead();
};

int myLL::deleteFromHead() 
{
    if (head == nullptr && tail == nullptr) //LL is empty
    {
        cout << "LL is empty" << endl;
        return NULL;
    }

    //single node case
    if (head == tail)
    {
        Node*temp = head;
        head = head->next;
        int returnValue = temp->data;
        delete temp;
        temp = nullptr;
        tail = nullptr;
        head = nullptr;
        return returnValue;
    }

    else //LL is not empty   
    {
        Node*temp = head;
        head = head->next;
        int returnValue = temp->data;
        delete temp;
        temp = nullptr;
        return returnValue;
    }
    
}

void myLL::insertAtHead(int value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->next = nullptr;

    if (head == nullptr && tail == nullptr) //LL is empty
    {
        head = nn;
        tail = nn;
    }

    else //non-empty LL
    {
       nn->next = head;
       head = nn;
    }
}

void myLL::display()
{

    if (head == nullptr && tail == nullptr)
        cout << "LL is empty" << endl;
    
    else 
    {
        Node*temp = head;

        while(1)
        {
            cout << temp->data << endl;
            temp = temp->next;

            if (temp == nullptr)
            break;
        }
    }
    
}

void myLL::insertAtTail(int value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->next = nullptr;

    if (head == nullptr && tail == nullptr) //LL is empty
    {
        head = nn;
        tail = nn;
    }

    else // when LL is not EMPTY
    {
        tail->next = nn;
        tail = nn;
    }
}