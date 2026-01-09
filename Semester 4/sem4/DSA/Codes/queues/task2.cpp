#include <iostream>
using namespace std;

#define max 10

class CircularQueue {
private:
    int arr[max];
    int front, rear;

public:
    
   CircularQueue() {
        front = -1;
        rear = -1;
    }

    
    bool isEmpty() {
        return front == -1;
    }

    
    bool isFull() {
        return (rear == max - 1) && (front == 0 || front > rear);
    }

    
    void Enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % max;
        }

        arr[rear] = value;
        cout << value << " enqueued to Queue.\n";
    }

    
    void Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        int removedValue = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % max;
        }

        cout << removedValue << " dequeued from Queue.\n";
    }

    
    void Peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek.\n";
            return;
        }

        cout << "front element: " << arr[front] << "\n";
    }
};

int main() 
{
   CircularQueue cq;

   cq.Enqueue(10);
   cq.Enqueue(20);
   cq.Enqueue(30);

   cq.Peek();

   cq.Dequeue();
   cq.Dequeue();

   cq.Peek();

   cq.Enqueue(40);
   cq.Enqueue(50);

   cq.Peek();

    return 0;
}
