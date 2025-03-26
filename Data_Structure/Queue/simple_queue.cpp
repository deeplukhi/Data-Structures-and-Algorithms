#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front, rear, capacity, size;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int val) {
        if (size == capacity) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int getFront() {
        if (size == 0) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Queue: ";
    q.printQueue();

    q.dequeue();
    cout << "After dequeue: ";
    q.printQueue();

    cout << "Front element: " << q.getFront() << endl;

    return 0;
}
