#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear, capacity, size;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void enqueue(int val) {
        if (size == capacity) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
        if (size == 0) front = rear = -1;
    }

    int getFront() {
        if (size == 0) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    void printQueue() {
        if (size == 0) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << arr[index] << " ";
            index = (index + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout << "Circular Queue: ";
    cq.printQueue();

    cq.dequeue();
    cout << "After dequeue: ";
    cq.printQueue();

    cout << "Front element: " << cq.getFront() << endl;

    return 0;
}
