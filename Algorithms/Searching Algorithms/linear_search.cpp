#include <iostream>
using namespace std;

// Function to perform Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; // Return the index of the target element
    }
    return -1; // Return -1 if target is not found
}

// Driver function
int main() {
    int arr[] = {10, 25, 30, 15, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the element to search: ";
    cin >> target;

    int result = linearSearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
