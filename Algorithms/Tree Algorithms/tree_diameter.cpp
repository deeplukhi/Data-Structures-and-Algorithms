#include <iostream>
using namespace std;

// Definition of a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Utility function to compute diameter using DFS
int findDiameter(TreeNode* root, int& diameter) {
    if (!root) return 0;

    int leftHeight = findDiameter(root->left, diameter);
    int rightHeight = findDiameter(root->right, diameter);

    // Update maximum diameter found so far
    diameter = max(diameter, leftHeight + rightHeight);

    // Return height of current node
    return max(leftHeight, rightHeight) + 1;
}

// Function to calculate Tree Diameter
int treeDiameter(TreeNode* root) {
    int diameter = 0;
    findDiameter(root, diameter);
    return diameter;
}

// Driver function
int main() {
    // Creating a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    cout << "Tree Diameter: " << treeDiameter(root) << endl;

    return 0;
}
