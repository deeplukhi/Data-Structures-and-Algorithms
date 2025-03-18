#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    cout << "Original Vector: ";
    printVector(vec);

    // Adding elements
    vec.push_back(6);
    vec.push_back(7);
    cout << "After Pushing 6 and 7: ";
    printVector(vec);

    // Removing last element
    vec.pop_back();
    cout << "After Popping Last Element: ";
    printVector(vec);

    // Inserting an element at index 2
    vec.insert(vec.begin() + 2, 10);
    cout << "After Inserting 10 at index 2: ";
    printVector(vec);

    return 0;
}
