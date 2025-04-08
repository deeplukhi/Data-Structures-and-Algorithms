#include <iostream>
#include <vector>
using namespace std;

class HamiltonianGraph {
    int V;
    vector<vector<int>> adj;

public:
    HamiltonianGraph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    bool isHamiltonianPath(vector<int>& path, vector<bool>& visited, int pos) {
        if (pos == V) return true; // All vertices visited, Hamiltonian Path found

        for (int v : adj[path[pos - 1]]) {
            if (!visited[v]) {
                path[pos] = v;
                visited[v] = true;

                if (isHamiltonianPath(path, visited, pos + 1))
                    return true;

                visited[v] = false; // Backtrack
            }
        }
        return false;
    }

    bool findHamiltonianPath() {
        vector<int> path(V, -1);
        vector<bool> visited(V, false);

        for (int start = 0; start < V; start++) { // Try starting from each vertex
            path[0] = start;
            visited[start] = true;

            if (isHamiltonianPath(path, visited, 1)) {
                cout << "Hamiltonian Path: ";
                for (int v : path) cout << v << " ";
                cout << endl;
                return true;
            }
            visited[start] = false;
        }
        cout << "No Hamiltonian Path exists.\n";
        return false;
    }

    bool findHamiltonianCircuit() {
        vector<int> path(V, -1);
        vector<bool> visited(V, false);

        path[0] = 0;
        visited[0] = true;

        if (isHamiltonianPath(path, visited, 1)) {
            for (int v : adj[path[V - 1]]) {
                if (v == path[0]) { // Circuit condition
                    cout << "Hamiltonian Circuit: ";
                    for (int v : path) cout << v << " ";
                    cout << path[0] << endl;
                    return true;
                }
            }
        }
        cout << "No Hamiltonian Circuit exists.\n";
        return false;
    }
};

// Driver function
int main() {
    int V = 5;
    HamiltonianGraph g(V);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.addEdge(1, 3);

    g.findHamiltonianPath();
    g.findHamiltonianCircuit();

    return 0;
}
