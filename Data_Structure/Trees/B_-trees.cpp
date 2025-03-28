#include <iostream>
using namespace std;

// Define the order of the B-Tree
#define ORDER 3  

class BTreeNode {
public:
    int keys[ORDER - 1];  // Store keys
    BTreeNode* children[ORDER]; // Store child pointers
    int numKeys;
    bool isLeaf;

    BTreeNode(bool leaf) {
        isLeaf = leaf;
        numKeys = 0;
        for (int i = 0; i < ORDER; i++) {
            children[i] = nullptr;
        }
    }
};

class BTree {
private:
    BTreeNode* root;

public:
    BTree() { root = nullptr; }

    void traverse(BTreeNode* node) {
        if (node == nullptr) return;

        for (int i = 0; i < node->numKeys; i++) {
            if (!node->isLeaf) traverse(node->children[i]);
            cout << node->keys[i] << " ";
        }

        if (!node->isLeaf) traverse(node->children[node->numKeys]);
    }

    void insert(int key) {
        if (root == nullptr) {
            root = new BTreeNode(true);
            root->keys[0] = key;
            root->numKeys = 1;
        } else {
            // Implement B-Tree insertion logic here
            cout << "Insertion not fully implemented yet.\n";
        }
    }

    void print() {
        traverse(root);
        cout << endl;
    }
};

int main() {
    BTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.print();  // Expected Output (simplified): 5 10 20

    return 0;
}
