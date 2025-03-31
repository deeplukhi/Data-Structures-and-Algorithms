#include <iostream>
#include <vector>
using namespace std;

// Function to perform Counting Sort
void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Find the maximum value in the array
    int maxVal = *max_element(arr.begin(), arr.end());

    // Create a count array to store the frequency of each number
    vector<int> count(maxVal + 1, 0);

    // Count occurrences of each number
    for (int num : arr) {
        count[num]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
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
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    printArray(arr);

    countingSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
