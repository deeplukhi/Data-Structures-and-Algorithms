#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class EulerianGraph {
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    EulerianGraph(int V) : V(V), adj(V), visited(V, false) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void dfs(int u) {
        visited[u] = true;
        for (int v : adj[u])
            if (!visited[v])
                dfs(v);
    }

    bool isConnected() {
        // Find a vertex with a degree > 0
        int start = -1;
        for (int i = 0; i < V; i++)
            if (!adj[i].empty()) {
                start = i;
                break;
            }

        if (start == -1) return true; // No edges, graph is Eulerian

        // Perform DFS
        fill(visited.begin(), visited.end(), false);
        dfs(start);

        // Check if all non-zero degree vertices are visited
        for (int i = 0; i < V; i++)
            if (!adj[i].empty() && !visited[i])
                return false;

        return true;
    }

    int findEulerian() {
        if (!isConnected()) return 0; // Graph is not Eulerian

        int oddDegree = 0;
        for (int i = 0; i < V; i++)
            if (adj[i].size() % 2 != 0)
                oddDegree++;

        if (oddDegree == 0) return 2; // Eulerian Circuit
        if (oddDegree == 2) return 1; // Eulerian Path

        return 0; // Not Eulerian
    }

    void printResult() {
        int res = findEulerian();
        if (res == 0)
            cout << "Graph is NOT Eulerian.\n";
        else if (res == 1)
            cout << "Graph has an Eulerian PATH.\n";
        else
            cout << "Graph has an Eulerian CIRCUIT.\n";
    }
};

// Driver function
int main() {
    int V = 5;
    EulerianGraph g(V);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.printResult();

    return 0;
}
