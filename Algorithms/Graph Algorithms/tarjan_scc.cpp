#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TarjanSCC {
    int V, timer;
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<bool> inStack;
    stack<int> st;

public:
    TarjanSCC(int V) : V(V), adj(V), disc(V, -1), low(V, -1), inStack(V, false), timer(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int u) {
        disc[u] = low[u] = timer++;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u]) {
            if (disc[v] == -1) {  // If `v` is not visited
                dfs(v);
                low[u] = min(low[u], low[v]); // Update low-link value
            } else if (inStack[v]) { // If `v` is in stack, update low-link value
                low[u] = min(low[u], disc[v]);
            }
        }

        // If `u` is root of an SCC
        if (low[u] == disc[u]) {
            cout << "SCC: ";
            while (true) {
                int node = st.top();
                st.pop();
                inStack[node] = false;
                cout << node << " ";
                if (node == u) break;
            }
            cout << endl;
        }
    }

    void findSCCs() {
        for (int i = 0; i < V; i++)
            if (disc[i] == -1)
                dfs(i);
    }
};

// Driver function
int main() {
    int V = 5;
    TarjanSCC graph(V);

    graph.addEdge(0, 2);
    graph.addEdge(2, 1);
    graph.addEdge(1, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    cout << "Strongly Connected Components:\n";
    graph.findSCCs();

    return 0;
}
