#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add a directed edge u -> v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Kahn's Algorithm (BFS-based Topological Sort)
    void topologicalSortBFS() {
        vector<int> inDegree(V, 0);
        queue<int> q;

        // Compute in-degree for each node
        for (int i = 0; i < V; i++) {
            for (int v : adj[i]) {
                inDegree[v]++;
            }
        }

        // Push nodes with in-degree 0 to queue
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        cout << "Topological Sort (BFS - Kahn's Algorithm): ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (--inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        cout << endl;
    }

    // DFS-Based Topological Sort Helper
    void dfs(int node, vector<bool>& visited, stack<int>& topoStack) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, topoStack);
            }
        }
        topoStack.push(node);
    }

    // DFS-Based Topological Sort
    void topologicalSortDFS() {
        vector<bool> visited(V, false);
        stack<int> topoStack;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, topoStack);
            }
        }

        cout << "Topological Sort (DFS-Based): ";
        while (!topoStack.empty()) {
            cout << topoStack.top() << " ";
            topoStack.pop();
        }
        cout << endl;
    }
};

// Driver function
int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sorting of the Graph:\n";
    g.topologicalSortBFS();
    g.topologicalSortDFS();

    return 0;
}
