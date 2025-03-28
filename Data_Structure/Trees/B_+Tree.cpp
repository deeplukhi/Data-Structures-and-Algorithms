#include <iostream>
using namespace std;

#define MAX_KEYS 3  // Order of the B+ tree

class BPlusTreeNode {
public:
    int keys[MAX_KEYS];
    BPlusTreeNode* children[MAX_KEYS + 1];
    int numKeys;
    bool isLeaf;

    BPlusTreeNode(bool leaf) {
        isLeaf = leaf;
        numKeys = 0;
        for (int i = 0; i < MAX_KEYS + 1; i++) {
            children[i] = nullptr;
        }
    }
};

class BPlusTree {
private:
    BPlusTreeNode* root;

public:
    BPlusTree() { root = nullptr; }

    void insert(int key) {
        cout << "Insertion logic for B+ tree not implemented yet." << endl;
    }

    void print() {
        cout << "Printing logic for B+ tree not implemented yet." << endl;
    }
};

int main() {
    BPlusTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.print();  // Output placeholder

    return 0;
}
