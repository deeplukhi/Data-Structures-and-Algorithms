#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array (Lomuto Partition Scheme)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choosing last element as pivot
    int i = low - 1;        // Pointer for smaller elements

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Swap smaller element to correct position
        }
    }
    swap(arr[i + 1], arr[high]);  // Place pivot at its correct position
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);  // Sort left half
        quickSort(arr, pivotIndex + 1, high); // Sort right half
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
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
