#include <iostream>
using namespace std;

// Red-Black Tree Node Structure
enum Color { RED, BLACK };

class Node {
public:
    int data;
    Color color;
    Node* left, * right, * parent;

    Node(int val) {
        data = val;
        color = RED;  // New nodes are always RED initially
        left = right = parent = nullptr;
    }
};

class RedBlackTree {
private:
    Node* root;

    void rotateLeft(Node*& node) {
        Node* rightChild = node->right;
        node->right = rightChild->left;
        if (rightChild->left) rightChild->left->parent = node;
        rightChild->parent = node->parent;
        if (!node->parent) root = rightChild;
        else if (node == node->parent->left) node->parent->left = rightChild;
        else node->parent->right = rightChild;
        rightChild->left = node;
        node->parent = rightChild;
    }

    void rotateRight(Node*& node) {
        Node* leftChild = node->left;
        node->left = leftChild->right;
        if (leftChild->right) leftChild->right->parent = node;
        leftChild->parent = node->parent;
        if (!node->parent) root = leftChild;
        else if (node == node->parent->right) node->parent->right = leftChild;
        else node->parent->left = leftChild;
        leftChild->right = node;
        node->parent = leftChild;
    }

    void fixViolation(Node*& node) {
        Node* parent = nullptr;
        Node* grandparent = nullptr;

        while (node != root && node->color == RED && node->parent->color == RED) {
            parent = node->parent;
            grandparent = parent->parent;

            // Parent is left child of grandparent
            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;

                // Case 1: Uncle is RED (Recoloring)
                if (uncle && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    // Case 2: Node is right child -> Left Rotation
                    if (node == parent->right) {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    // Case 3: Node is left child -> Right Rotation
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
            // Parent is right child of grandparent
            else {
                Node* uncle = grandparent->left;

                // Case 1: Uncle is RED (Recoloring)
                if (uncle && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    // Case 2: Node is left child -> Right Rotation
                    if (node == parent->left) {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    // Case 3: Node is right child -> Left Rotation
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
        }
        root->color = BLACK; // Root must always be BLACK
    }

public:
    RedBlackTree() {
        root = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            root->color = BLACK;
            return;
        }

        Node* parent = nullptr;
        Node* temp = root;
        while (temp) {
            parent = temp;
            if (val < temp->data) temp = temp->left;
            else temp = temp->right;
        }

        newNode->parent = parent;
        if (val < parent->data) parent->left = newNode;
        else parent->right = newNode;

        fixViolation(newNode);
    }

    void inorderTraversal(Node* root) {
        if (!root) return;
        inorderTraversal(root->left);
        cout << root->data << "(" << (root->color == RED ? "R" : "B") << ") ";
        inorderTraversal(root->right);
    }

    void printTree() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);
    rbt.insert(5);
    rbt.insert(1);

    cout << "Inorder Traversal (Red-Black Tree):" << endl;
    rbt.printTree();

    return 0;
}


// Inorder Traversal (Red-Black Tree):
// 1(B) 5(R) 10(B) 15(R) 20(B) 25(R) 30(B)
