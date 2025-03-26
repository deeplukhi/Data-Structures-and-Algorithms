#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);

    cout << "Deque elements: ";
    for (int num : dq) cout << num << " ";
    cout << endl;

    dq.pop_back();
    cout << "After pop_back: ";
    for (int num : dq) cout << num << " ";
    cout << endl;

    dq.pop_front();
    cout << "After pop_front: ";
    for (int num : dq) cout << num << " ";
    cout << endl;

    return 0;
}
