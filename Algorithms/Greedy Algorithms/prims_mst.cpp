#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

// Function to find the Minimum Spanning Tree using Prim's Algorithm
void primMST(int V, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap (weight, node)
    vector<int> key(V, INT_MAX);  // Key values for min-weight edges
    vector<int> parent(V, -1);    // Stores MST
    vector<bool> inMST(V, false); // MST inclusion flag

    // Start from node 0
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; // Get the node with the minimum weight edge
        pq.pop();
        
        if (inMST[u]) continue;
        inMST[u] = true; // Include this node in MST

        // Process all adjacent vertices of u
        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({weight, v});
            }
        }
    }

    // Display the MST edges
    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
    }
}

// Driver function
int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    // Graph edges (undirected)
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    primMST(V, adj);

    return 0;
}
