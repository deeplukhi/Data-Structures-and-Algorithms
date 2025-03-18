#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Declaration and Initialization
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;

    cout << "Original Array: ";
    printArray(arr, size);

    // Updating an element
    arr[2] = 10;
    cout << "After Updating arr[2] to 10: ";
    printArray(arr, size);

    // Searching for an element
    int key = 4;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element " << key << " found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Element " << key << " not found." << endl;

    return 0;
}
