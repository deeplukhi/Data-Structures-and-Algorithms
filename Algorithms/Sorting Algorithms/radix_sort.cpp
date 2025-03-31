#include <iostream>
#include <vector>
using namespace std;

// Function to perform Counting Sort based on a specific digit (exp)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Output array
    vector<int> count(10, 0); // Count array for digits 0-9

    // Count occurrences of each digit at the current place (exp)
    for (int num : arr)
        count[(num / exp) % 10]++;

    // Update count[i] to store the position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy sorted elements back to the original array
    arr = output;
}

// Function to perform Radix Sort
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Find the maximum number to know the number of digits
    int maxVal = *max_element(arr.begin(), arr.end());

    // Apply counting sort for each digit (from least significant to most significant)
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Driver function
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    printArray(arr);

    radixSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}