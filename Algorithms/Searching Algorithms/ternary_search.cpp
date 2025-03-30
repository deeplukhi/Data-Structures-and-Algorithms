#include <iostream>
using namespace std;

// Function to perform Ternary Search (Iterative)
int ternarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;

        if (target < arr[mid1]) {
            right = mid1 - 1; // Search in the left part
        } 
        else if (target > arr[mid2]) {
            left = mid2 + 1; // Search in the right part
        } 
        else {
            left = mid1 + 1;
            right = mid2 - 1; // Search in the middle part
        }
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

    int result = ternarySearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}




// C++ Implementation of Recursive Ternary Search

#include <iostream>
using namespace std;

// Function to perform Ternary Search (Recursive)
int ternarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right)
        return -1; // Base case: target not found

    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if (arr[mid1] == target) return mid1;
    if (arr[mid2] == target) return mid2;

    if (target < arr[mid1]) 
        return ternarySearchRecursive(arr, left, mid1 - 1, target); // Search left part
    else if (target > arr[mid2]) 
        return ternarySearchRecursive(arr, mid2 + 1, right, target); // Search right part
    else 
        return ternarySearchRecursive(arr, mid1 + 1, mid2 - 1, target); // Search middle part
}

// Driver function
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the element to search: ";
    cin >> target;

    int result = ternarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
