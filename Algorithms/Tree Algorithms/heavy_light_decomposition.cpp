#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5; // Maximum nodes

vector<int> tree[N];  // Adjacency list representation of tree
int parent[N], depth[N], subtree_size[N];
int heavy_child[N], chain_head[N], position[N], base_array[N], segTree[N * 4];
int current_pos = 0;

// Step 1: DFS to compute subtree sizes and find heavy edges
void dfs(int node, int par) {
    parent[node] = par;
    depth[node] = (par == -1) ? 0 : depth[par] + 1;
    subtree_size[node] = 1;
    heavy_child[node] = -1;
    
    int max_size = 0;
    for (int child : tree[node]) {
        if (child == par) continue; // Skip parent
        dfs(child, node);
        subtree_size[node] += subtree_size[child];

        // Update heavy child (largest subtree)
        if (subtree_size[child] > max_size) {
            max_size = subtree_size[child];
            heavy_child[node] = child;
        }
    }
}

// Step 2: HLD - Decompose the tree into heavy-light chains
void hld(int node, int head) {
    chain_head[node] = head;
    position[node] = current_pos;
    base_array[current_pos++] = node; // Store node in linear array

    if (heavy_child[node] != -1)
        hld(heavy_child[node], head); // Continue heavy chain

    for (int child : tree[node]) {
        if (child != parent[node] && child != heavy_child[node]) {
            hld(child, child); // Start new chain
        }
    }
}

// Segment Tree: Build, Update, Query (for path queries)
void buildSegTree(int node, int start, int end) {
    if (start == end) {
        segTree[node] = base_array[start]; // Assign node value
        return;
    }
    int mid = (start + end) / 2;
    buildSegTree(2 * node, start, mid);
    buildSegTree(2 * node + 1, mid + 1, end);
    segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]); // Example: max query
}

// Query path from node u to node v
int queryPath(int u, int v) {
    int res = 0;
    while (chain_head[u] != chain_head[v]) {
        if (depth[chain_head[u]] < depth[chain_head[v]]) swap(u, v);
        // Query segment from position[chain_head[u]] to position[u]
        u = parent[chain_head[u]]; // Move to next chain
    }
    if (depth[u] > depth[v]) swap(u, v);
    // Final segment query from position[u] to position[v]
    return res;
}

// Driver function
int main() {
    int n = 9; // Number of nodes
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {6, 8}, {6, 9}};
    
    // Construct tree
    for (auto edge : edges) {
        int u = edge.first, v = edge.second;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Step 1: DFS to find heavy edges
    dfs(1, -1);
    
    // Step 2: Perform HLD
    hld(1, 1);

    // Step 3: Build Segment Tree
    buildSegTree(1, 0, n - 1);

    // Example query
    cout << "Path Query from 4 to 9: " << queryPath(4, 9) << endl;

    return 0;
}
