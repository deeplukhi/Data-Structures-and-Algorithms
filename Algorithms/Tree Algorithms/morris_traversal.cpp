#include <iostream>
using namespace std;

// Definition of a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform Morris Traversal (Inorder)
void morrisTraversal(TreeNode* root) {
    TreeNode* current = root;

    while (current) {
        if (!current->left) {
            cout << current->val << " ";
            current = current->right; // Move to right subtree
        } else {
            // Find the inorder predecessor (rightmost node in left subtree)
            TreeNode* predecessor = current->left;
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (!predecessor->right) {
                // Establish a temporary link to current node
                predecessor->right = current;
                current = current->left;
            } else {
                // Remove the temporary link and process the node
                predecessor->right = NULL;
                cout << current->val << " ";
                current = current->right;
            }
        }
    }
}

// Driver function
int main() {
    // Creating a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform Morris Inorder Traversal
    cout << "Morris Inorder Traversal: ";
    morrisTraversal(root);
    cout << endl;

    return 0;
}
