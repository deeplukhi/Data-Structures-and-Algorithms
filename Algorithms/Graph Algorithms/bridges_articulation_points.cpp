#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int V, timer;
    vector<vector<int>> adj;
    vector<int> disc, low, parent;
    vector<bool> visited, isArticulation;
    
public:
    Graph(int V) : V(V), adj(V), disc(V, -1), low(V, -1), parent(V, -1),
                   visited(V, false), isArticulation(V, false), timer(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void dfs(int u) {
        visited[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {  // If `v` is not visited
                children++;
                parent[v] = u;
                dfs(v);

                low[u] = min(low[u], low[v]);

                // Check for articulation point
                if (parent[u] == -1 && children > 1)
                    isArticulation[u] = true;  // Root node with multiple children
                if (parent[u] != -1 && low[v] >= disc[u])
                    isArticulation[u] = true;  // Non-root node condition

                // Check for bridge
                if (low[v] > disc[u])
                    cout << "Bridge: " << u << " - " << v << endl;
            } else if (v != parent[u]) {  // Back edge (cycle detection)
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    void findBridgesAndArticulationPoints() {
        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs(i);

        cout << "Articulation Points: ";
        for (int i = 0; i < V; i++)
            if (isArticulation[i])
                cout << i << " ";
        cout << endl;
    }
};

// Driver function
int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    cout << "Finding Bridges & Articulation Points:\n";
    g.findBridgesAndArticulationPoints();

    return 0;
}
