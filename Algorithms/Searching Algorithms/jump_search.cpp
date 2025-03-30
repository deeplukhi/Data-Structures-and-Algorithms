#include <iostream>
#include <cmath> // For sqrt()
using namespace std;

// Function to perform Jump Search
int jumpSearch(int arr[], int n, int target) {
    int step = sqrt(n); // Step size = √N
    int prev = 0;

    // Jump ahead in blocks of size `step`
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1; // If end is reached, target is not present
    }

    // Perform linear search in the identified block
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Driver function
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the element to search: ";
    cin >> target;

    int result = jumpSearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
