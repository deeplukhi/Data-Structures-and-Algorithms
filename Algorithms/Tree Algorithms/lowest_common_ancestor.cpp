#include <iostream>
using namespace std;

// Definition of a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find Lowest Common Ancestor (LCA)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA && rightLCA) return root; // Both found, this is LCA
    return leftLCA ? leftLCA : rightLCA;  // Else return the non-null one
}

// Driver function
int main() {
    // Creating a sample tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;       // Node 5
    TreeNode* q = root->left->right->right; // Node 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}
