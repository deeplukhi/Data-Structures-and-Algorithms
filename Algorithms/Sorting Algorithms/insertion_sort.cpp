#include <iostream>
#include <vector>
using namespace std;

// Insertion Sort Function
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Current element to be inserted
        int j = i - 1;

        // Shift elements to the right to create the correct position for key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Insert key at the correct position
    }
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Driver function
int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original array: ";
    printArray(arr);

    insertionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
