#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to perform DFS and store vertices in a stack
void dfs1(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& s) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs1(v, adj, visited, s);
    s.push(u); // Push node to stack after visiting all neighbors
}

// Function to perform DFS on transposed graph and print SCC
void dfs2(int u, vector<vector<int>>& adjT, vector<bool>& visited) {
    cout << u << " ";
    visited[u] = true;
    for (int v : adjT[u])
        if (!visited[v])
            dfs2(v, adjT, visited);
}

// Kosaraju's Algorithm to find SCCs
void kosaraju(int V, vector<vector<int>>& adj) {
    stack<int> s;
    vector<bool> visited(V, false);

    // Step 1: Perform DFS and store finishing order in stack
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs1(i, adj, visited, s);

    // Step 2: Transpose the graph (reverse edges)
    vector<vector<int>> adjT(V);
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            adjT[v].push_back(u);

    // Step 3: Process nodes in order of decreasing finish time
    fill(visited.begin(), visited.end(), false);
    cout << "Strongly Connected Components:\n";
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!visited[u]) {
            dfs2(u, adjT, visited);
            cout << endl;
        }
    }
}

// Driver function
int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Directed graph edges
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);

    kosaraju(V, adj);

    return 0;
}
