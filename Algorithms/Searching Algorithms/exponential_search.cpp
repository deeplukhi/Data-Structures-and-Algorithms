#include <iostream>
using namespace std;

// Function to perform Binary Search (used inside Exponential Search)
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Function to perform Exponential Search
int exponentialSearch(int arr[], int n, int target) {
    if (arr[0] == target) return 0;

    int i = 1;
    while (i < n && arr[i] <= target) {
        i *= 2; // Exponential growth
    }

    // Perform Binary Search in the found range
    return binarySearch(arr, i / 2, min(i, n - 1), target);
}

// Driver function
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the element to search: ";
    cin >> target;

    int result = exponentialSearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
