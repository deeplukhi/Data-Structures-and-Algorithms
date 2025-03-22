// A Sparse Table is a data structure that allows efficient range queries on a static array, particularly:

// Range Minimum Query (RMQ)
// Range Maximum Query
// Greatest Common Divisor (GCD) Queries
// Sum Queries (without updates)
// ✔ Preprocessing Time: O(N log N)
// ✔ Query Time: O(1)
// ✔ Limitation: Does not support updates (only works for static arrays).


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SparseTable {
private:
    vector<vector<int>> st;
    vector<int> logTable;
    int N, K;

public:
    // Construct Sparse Table for Range Minimum Query (RMQ)
    SparseTable(vector<int> &arr) {
        N = arr.size();
        K = log2(N) + 1;
        st.assign(N, vector<int>(K));
        logTable.resize(N + 1);

        // Precompute log values
        for (int i = 2; i <= N; i++)
            logTable[i] = logTable[i / 2] + 1;

        // Initialize table for interval length 1
        for (int i = 0; i < N; i++)
            st[i][0] = arr[i];

        // Build Sparse Table
        for (int j = 1; (1 << j) <= N; j++) {
            for (int i = 0; i + (1 << j) <= N; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // Query for minimum in range [L, R]
    int query(int L, int R) {
        int j = logTable[R - L + 1];
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

int main() {
    vector<int> arr = {1, 3, -1, 7, 5, 6, 2, 4};
    SparseTable st(arr);

    // Queries
    cout << "Min(1, 3): " << st.query(1, 3) << endl; // Output: -1
    cout << "Min(4, 7): " << st.query(4, 7) << endl; // Output: 2
    cout << "Min(0, 5): " << st.query(0, 5) << endl; // Output: -1

    return 0;
}
