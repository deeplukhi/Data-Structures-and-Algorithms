#include <iostream>
using namespace std;

// Definition of a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to convert Binary Tree to DLL (Inorder Traversal)
void treeToDLL(TreeNode* root, TreeNode*& head, TreeNode*& prev) {
    if (!root) return;

    // Recursive call to left subtree
    treeToDLL(root->left, head, prev);

    // Process current node
    if (!prev) {
        head = root;  // First node becomes head
    } else {
        prev->right = root;
        root->left = prev;
    }
    prev = root; // Move prev to current node

    // Recursive call to right subtree
    treeToDLL(root->right, head, prev);
}

// Function to print DLL from left to right
void printDLL(TreeNode* head) {
    TreeNode* temp = head;
    while (temp) {
        cout << temp->val;
        if (temp->right) cout << " <-> ";
        temp = temp->right;
    }
    cout << " -> NULL" << endl;
}

// Driver function
int main() {
    // Creating a sample tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(30);

    // Convert to DLL
    TreeNode* head = NULL; // Head of the DLL
    TreeNode* prev = NULL; // Previous node in DLL
    treeToDLL(root, head, prev);

    // Print the Doubly Linked List
    cout << "Doubly Linked List: ";
    printDLL(head);

    return 0;
}