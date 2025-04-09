#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Comparator function to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set (Union-Find) with Path Compression
class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int u) {
        if (u != parent[u]) parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }
    
    void unite(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Function to find Minimum Spanning Tree using Kruskal's Algorithm
void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare); // Sort edges by weight
    DisjointSet ds(V);
    
    vector<Edge> mst; // Stores the MST edges
    int mstCost = 0;

    for (Edge& edge : edges) {
        if (ds.find(edge.src) != ds.find(edge.dest)) {
            mst.push_back(edge);
            mstCost += edge.weight;
            ds.unite(edge.src, edge.dest);
        }
    }

    // Display the MST edges
    cout << "Minimum Spanning Tree Edges:\n";
    for (auto& edge : mst) {
        cout << edge.src << " - " << edge.dest << " (Weight: " << edge.weight << ")\n";
    }

    // Display the total cost of the MST
    cout << "Total Cost of MST: " << mstCost << endl;
}

int main() {
    // Example usage
    int V = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Find and display the MST
    kruskalMST(V, edges);

    return 0;
}