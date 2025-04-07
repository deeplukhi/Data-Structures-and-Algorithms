#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
    vector<int> tree, lazy;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build(vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, l, r, val);
        updateRange(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int queryRange(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l) return 0;

        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        int leftQuery = queryRange(2 * node + 1, start, mid, l, r);
        int rightQuery = queryRange(2 * node + 2, mid + 1, end, l, r);
        return leftQuery + rightQuery;
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();
    SegmentTree segTree(n);
    segTree.build(arr, 0, 0, n - 1);
    
    cout << "Sum of range (1,3): " << segTree.queryRange(0, 0, n - 1, 1, 3) << endl;
    segTree.updateRange(0, 0, n - 1, 1, 3, 3);
    cout << "Sum of range (1,3) after update: " << segTree.queryRange(0, 0, n - 1, 1, 3) << endl;
    
    return 0;
}
