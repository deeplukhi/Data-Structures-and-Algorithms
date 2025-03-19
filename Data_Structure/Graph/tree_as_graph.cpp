#include <iostream>
#include <vector>
using namespace std;

class Tree {
private:
    int N;  // Number of nodes
    vector<vector<int>> adjList; // Adjacency list representation

public:
    Tree(int nodes) {
        N = nodes;
        adjList.resize(N);
    }

    // Add edge (Tree is an undirected graph)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Print Tree Representation (Adjacency List)
    void printTree() {
        cout << "Tree Representation (Adjacency List):\n";
        for (int i = 0; i < N; i++) {
            cout << i << " -> ";
            for (int v : adjList[i])
                cout << v << " ";
            cout << endl;
        }
    }
};

int main() {
    int nodes = 5;

    // Creating a tree
    Tree tree(nodes);
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(1, 3);
    tree.addEdge(1, 4);

    // Printing the tree
    tree.printTree();

    return 0;
}
