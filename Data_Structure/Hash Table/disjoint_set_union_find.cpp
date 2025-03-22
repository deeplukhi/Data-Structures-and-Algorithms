#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    // Initialize N disjoint sets
    DisjointSet(int N) {
        parent.resize(N);
        rank.resize(N, 0);
        for (int i = 0; i < N; i++)
            parent[i] = i; // Each element is its own parent initially
    }

    // Find with Path Compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    // Union by Rank
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    // Check if two elements belong to the same set
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    // Print parent array (for debugging)
    void printParents() {
        cout << "Parent Array: ";
        for (int i = 0; i < parent.size(); i++)
            cout << parent[i] << " ";
        cout << endl;
    }
};

int main() {
    DisjointSet ds(7); // Create 7 disjoint sets (0 to 6)

    ds.unionSets(1, 2);
    ds.unionSets(2, 3);
    ds.unionSets(4, 5);
    
    cout << "Are 1 and 3 connected? " << (ds.isConnected(1, 3) ? "Yes" : "No") << endl;
    cout << "Are 1 and 4 connected? " << (ds.isConnected(1, 4) ? "Yes" : "No") << endl;

    ds.unionSets(3, 4); // Connect component (1,2,3) with (4,5)
    
    cout << "Are 1 and 4 connected now? " << (ds.isConnected(1, 4) ? "Yes" : "No") << endl;
    
    ds.printParents(); // Debugging

    return 0;
}
