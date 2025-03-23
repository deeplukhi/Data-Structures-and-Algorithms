#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void deleteNode(int key) {
        if (!head) return;
        Node* temp = head, *prev = nullptr;
        if (head->data == key && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        do {
            if (temp->data == key) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    last->next = head->next;
                    head = head->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
    }

    void printList() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insertAtEnd(5);
    list.insertAtEnd(10);
    list.insertAtEnd(15);
    cout << "Circular Linked List: ";
    list.printList();

    list.deleteNode(10);
    cout << "After Deletion of 10: ";
    list.printList();

    return 0;
}
