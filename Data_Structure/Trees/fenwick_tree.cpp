#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> BIT;
    int n;

    // Internal function to get the sum from [1, idx]
    int prefixSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += BIT[idx];
            idx -= (idx & -idx);  // Move to parent
        }
        return sum;
    }

public:
    FenwickTree(int size) {
        n = size;
        BIT.assign(n + 1, 0);  // 1-based index
    }

    // Point update: Adds value to index idx
    void update(int idx, int value) {
        while (idx <= n) {
            BIT[idx] += value;
            idx += (idx & -idx);  // Move to next index
        }
    }

    // Query sum of elements in range [1, idx]
    int query(int idx) {
        return prefixSum(idx);
    }

    // Range sum query: sum of elements in [L, R]
    int rangeSum(int L, int R) {
        return prefixSum(R) - prefixSum(L - 1);
    }
};

int main() {
    vector<int> arr = {0, 3, 2, -1, 6, 5, 4, -3};  // 1-based indexing
    int n = arr.size() - 1;  // Ignore index 0

    FenwickTree ft(n);
    
    // Build the Fenwick Tree by adding elements one by one
    for (int i = 1; i <= n; i++) {
        ft.update(i, arr[i]);
    }

    cout << "Sum of range [2, 5]: " << ft.rangeSum(2, 5) << endl; // Output: 12
    cout << "Sum of range [1, 7]: " << ft.rangeSum(1, 7) << endl; // Output: 16

    ft.update(4, 3);  // Add 3 to arr[4]
    cout << "After update, sum of range [2, 5]: " << ft.rangeSum(2, 5) << endl; // Output: 15

    return 0;
}



// Sum of range [2, 5]: 12
// Sum of range [1, 7]: 16
// After update, sum of range [2, 5]: 15
