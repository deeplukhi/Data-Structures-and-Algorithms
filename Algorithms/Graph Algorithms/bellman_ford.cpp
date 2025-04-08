#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to find shortest paths using Bellman-Ford Algorithm
void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
            cout << "Graph contains a negative-weight cycle!\n";
            return;
        }
    }

    // Display shortest distances
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << "\n";
    }
}

// Driver function
int main() {
    int V = 5, E = 8;
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(V, E, edges, 0);

    return 0;
}
