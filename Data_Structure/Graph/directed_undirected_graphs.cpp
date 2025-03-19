#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency List for graph

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    // Add edge for an UNDIRECTED graph
    void addUndirectedEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Add edge for a DIRECTED graph
    void addDirectedEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // Print adjacency list representation
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adjList[i])
                cout << v << " ";
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;
    
    // Undirected Graph Example
    cout << "Undirected Graph Representation:\n";
    Graph undirectedGraph(vertices);
    undirectedGraph.addUndirectedEdge(0, 1);
    undirectedGraph.addUndirectedEdge(0, 4);
    undirectedGraph.addUndirectedEdge(1, 2);
    undirectedGraph.addUndirectedEdge(1, 3);
    undirectedGraph.addUndirectedEdge(1, 4);
    undirectedGraph.addUndirectedEdge(2, 3);
    undirectedGraph.addUndirectedEdge(3, 4);
    undirectedGraph.printGraph();

    // Directed Graph Example
    cout << "\nDirected Graph Representation:\n";
    Graph directedGraph(vertices);
    directedGraph.addDirectedEdge(0, 1);
    directedGraph.addDirectedEdge(0, 4);
    directedGraph.addDirectedEdge(1, 2);
    directedGraph.addDirectedEdge(1, 3);
    directedGraph.addDirectedEdge(1, 4);
    directedGraph.addDirectedEdge(2, 3);
    directedGraph.addDirectedEdge(3, 4);
    directedGraph.printGraph();

    return 0;
}
