#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency List
    vector<vector<int>> adjMatrix; // Adjacency Matrix

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    // Add edge for adjacency list
    void addEdgeList(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected graph
    }

    // Add edge for adjacency matrix
    void addEdgeMatrix(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Undirected graph
    }

    // Print adjacency list
    void printAdjList() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adjList[i])
                cout << v << " ";
            cout << endl;
        }
    }

    // Print adjacency matrix
    void printAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    // Add edges
    g.addEdgeList(0, 1);
    g.addEdgeList(0, 4);
    g.addEdgeList(1, 2);
    g.addEdgeList(1, 3);
    g.addEdgeList(1, 4);
    g.addEdgeList(2, 3);
    g.addEdgeList(3, 4);

    g.addEdgeMatrix(0, 1);
    g.addEdgeMatrix(0, 4);
    g.addEdgeMatrix(1, 2);
    g.addEdgeMatrix(1, 3);
    g.addEdgeMatrix(1, 4);
    g.addEdgeMatrix(2, 3);
    g.addEdgeMatrix(3, 4);

    // Print graph representations
    g.printAdjList();
    g.printAdjMatrix();

    return 0;
}
