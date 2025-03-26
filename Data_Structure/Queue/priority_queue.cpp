#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);

    cout << "Max Heap (Priority Queue): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    cout << "Min Heap (Priority Queue): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
