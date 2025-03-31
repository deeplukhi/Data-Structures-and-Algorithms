#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Bucket Sort
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // Step 1: Create n empty buckets
    vector<vector<float>> buckets(n);

    // Step 2: Distribute elements into different buckets
    for (float num : arr) {
        int index = n * num; // Index calculation (assuming input is in [0,1) range)
        buckets[index].push_back(num);
    }

    // Step 3: Sort individual buckets using any sorting algorithm (Insertion Sort here)
    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Step 4: Concatenate all sorted buckets into the original array
    int idx = 0;
    for (int i = 0; i < n; i++)
        for (float num : buckets[i])
            arr[idx++] = num;
}

// Utility function to print an array
void printArray(const vector<float>& arr) {
    for (float num : arr)
        cout << num << " ";
    cout << endl;
}

// Driver function
int main() {
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    cout << "Original array: ";
    printArray(arr);

    bucketSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
