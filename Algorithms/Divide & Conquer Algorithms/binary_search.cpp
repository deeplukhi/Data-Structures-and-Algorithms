#include <iostream>
using namespace std;

// Function to perform Binary Search (Iterative)
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is found
        if (arr[mid] == target)
            return mid;

        // If target is smaller, search the left half
        if (arr[mid] > target)
            right = mid - 1;
        else // If target is larger, search the right half
            left = mid + 1;
    }

    return -1; // Target not found
}

// Driver function
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the element to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
