#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Huffman Tree Node
struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode *left, *right;
    
    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparator for min-heap priority queue
struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq; // Min-heap (lower frequency has higher priority)
    }
};

// Function to print Huffman Codes
void printCodes(HuffmanNode* root, string str) {
    if (!root) return;
    if (root->data != '$') // Leaf node (valid character)
        cout << root->data << ": " << str << endl;
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to build Huffman Tree and print codes
void huffmanCoding(vector<char> chars, vector<int> freqs) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;
    
    for (size_t i = 0; i < chars.size(); i++)
        minHeap.push(new HuffmanNode(chars[i], freqs[i]));
    
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();
        
        HuffmanNode* merged = new HuffmanNode('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        
        minHeap.push(merged);
    }
    
    cout << "Huffman Codes:\n";
    printCodes(minHeap.top(), "");
}

// Driver function
int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freqs = {5, 9, 12, 13, 16, 45};
    
    huffmanCoding(chars, freqs);
    return 0;
}
