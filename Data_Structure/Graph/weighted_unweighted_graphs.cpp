#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> unweightedAdjList; // Unweighted Adjacency List
    vector<vector<pair<int, int>>> weightedAdjList; // Weighted Adjacency List

public:
    Graph(int vertices) {
        V = vertices;
        unweightedAdjList.resize(V);
        weightedAdjList.resize(V);
    }

    // Add edge for an UNWEIGHTED graph (Undirected)
    void addUnweightedEdge(int u, int v) {
        unweightedAdjList[u].push_back(v);
        unweightedAdjList[v].push_back(u);
    }

    // Add edge for a WEIGHTED graph (Undirected)
    void addWeightedEdge(int u, int v, int weight) {
        weightedAdjList[u].push_back({v, weight});
        weightedAdjList[v].push_back({u, weight});
    }

    // Print Unweighted Graph
    void printUnweightedGraph() {
        cout << "Unweighted Graph (Adjacency List):\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : unweightedAdjList[i])
                cout << v << " ";
            cout << endl;
        }
    }

    // Print Weighted Graph
    void printWeightedGraph() {
        cout << "\nWeighted Graph (Adjacency List):\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto edge : weightedAdjList[i])
                cout << "(" << edge.first << ", " << edge.second << ") ";
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;

    // Unweighted Graph Example
    cout << "Unweighted Graph Representation:\n";
    Graph unweightedGraph(vertices);
    unweightedGraph.addUnweightedEdge(0, 1);
    unweightedGraph.addUnweightedEdge(0, 4);
    unweightedGraph.addUnweightedEdge(1, 2);
    unweightedGraph.addUnweightedEdge(1, 3);
    unweightedGraph.addUnweightedEdge(1, 4);
    unweightedGraph.addUnweightedEdge(2, 3);
    unweightedGraph.addUnweightedEdge(3, 4);
    unweightedGraph.printUnweightedGraph();

    // Weighted Graph Example
    cout << "\nWeighted Graph Representation:\n";
    Graph weightedGraph(vertices);
    weightedGraph.addWeightedEdge(0, 1, 4);
    weightedGraph.addWeightedEdge(0, 4, 8);
    weightedGraph.addWeightedEdge(1, 2, 2);
    weightedGraph.addWeightedEdge(1, 3, 5);
    weightedGraph.addWeightedEdge(1, 4, 6);
    weightedGraph.addWeightedEdge(2, 3, 3);
    weightedGraph.addWeightedEdge(3, 4, 7);
    weightedGraph.printWeightedGraph();

    return 0;
}
