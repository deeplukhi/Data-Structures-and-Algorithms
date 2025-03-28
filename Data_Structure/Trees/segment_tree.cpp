#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;  // Segment tree array
    vector<int> arr;   // Original array
    int n;             // Size of the original array

    // Build the segment tree
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];  // Leaf node stores the array element
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];  // Sum of children
        }
    }

    // Range sum query
    int query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return 0;  // Completely outside
        if (L <= start && end <= R) return tree[node];  // Completely inside
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, L, R) + query(2 * node + 1, mid + 1, end, L, R);
    }

    // Point update (set arr[idx] = value)
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            arr[idx] = value;  // Update the original array
            tree[node] = value;  // Update the segment tree
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) update(2 * node, start, mid, idx, value);
            else update(2 * node + 1, mid + 1, end, idx, value);
            tree[node] = tree[2 * node] + tree[2 * node + 1];  // Recompute sum
        }
    }

public:
    SegmentTree(vector<int>& input) {
        arr = input;
        n = input.size();
        tree.resize(4 * n, 0);  // Allocate memory for segment tree
        build(1, 0, n - 1);  // Build the tree
    }

    int rangeSum(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }

    void updateValue(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << "Sum of range [1, 3]: " << st.rangeSum(1, 3) << endl; // Output: 15
    cout << "Sum of range [0, 5]: " << st.rangeSum(0, 5) << endl; // Output: 36

    st.updateValue(2, 10); // Update arr[2] = 10
    cout << "After update, sum of range [1, 3]: " << st.rangeSum(1, 3) << endl; // Output: 20

    return 0;
}


// Sum of range [1, 3]: 15
// Sum of range [0, 5]: 36
// After update, sum of range [1, 3]: 20
