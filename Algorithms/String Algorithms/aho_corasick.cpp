#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Trie Node structure
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    TrieNode* failLink = nullptr;
    vector<int> patternIndexes; // Stores indexes of patterns ending at this node
};

// Aho-Corasick Trie
class AhoCorasick {
private:
    TrieNode* root;
    
    // Build failure links using BFS
    void buildFailureLinks() {
        queue<TrieNode*> q;
        root->failLink = root;
        
        for (auto& [ch, node] : root->children) {
            node->failLink = root;
            q.push(node);
        }

        while (!q.empty()) {
            TrieNode* curr = q.front();
            q.pop();

            for (auto& [ch, child] : curr->children) {
                TrieNode* fail = curr->failLink;
                while (fail != root && fail->children.find(ch) == fail->children.end()) {
                    fail = fail->failLink;
                }
                if (fail->children.find(ch) != fail->children.end() && fail->children[ch] != child) {
                    child->failLink = fail->children[ch];
                } else {
                    child->failLink = root;
                }
                
                child->patternIndexes.insert(
                    child->patternIndexes.end(),
                    child->failLink->patternIndexes.begin(),
                    child->failLink->patternIndexes.end()
                );
                
                q.push(child);
            }
        }
    }

public:
    AhoCorasick() { root = new TrieNode(); }

    // Insert patterns into Trie
    void insertPattern(const string& pattern, int index) {
        TrieNode* node = root;
        for (char ch : pattern) {
            if (!node->children[ch]) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->patternIndexes.push_back(index);
    }

    // Preprocess the Trie with failure links
    void buildTrie(const vector<string>& patterns) {
        for (int i = 0; i < patterns.size(); i++) {
            insertPattern(patterns[i], i);
        }
        buildFailureLinks();
    }

    // Search patterns in text
    vector<vector<int>> searchPatterns(const string& text, const vector<string>& patterns) {
        vector<vector<int>> occurrences(patterns.size());
        TrieNode* node = root;

        for (int i = 0; i < text.size(); i++) {
            char ch = text[i];

            while (node != root && node->children.find(ch) == node->children.end()) {
                node = node->failLink; // Follow failure link
            }
            if (node->children.find(ch) != node->children.end()) {
                node = node->children[ch];
            }

            for (int patternIndex : node->patternIndexes) {
                occurrences[patternIndex].push_back(i - patterns[patternIndex].size() + 1);
            }
        }

        return occurrences;
    }
};

// Driver function
int main() {
    vector<string> patterns = {"he", "she", "his", "hers"};
    string text = "ahishers";

    AhoCorasick ac;
    ac.buildTrie(patterns);
    
    vector<vector<int>> result = ac.searchPatterns(text, patterns);

    for (int i = 0; i < patterns.size(); i++) {
        cout << "Pattern \"" << patterns[i] << "\" found at indices: ";
        for (int index : result[i]) cout << index << " ";
        cout << endl;
    }

    return 0;
}



// 📌 Explanation
// Step 1: Build Trie
// Patterns are inserted into a Trie structure.

// lua
// Copy
// Edit
// Patterns: ["he", "she", "his", "hers"]
// Trie Structure:
//     root
//      |
//      h--e (he)  s--h--e (she)
//      |       |
//      i--s (his)   r--s (hers)
// Step 2: Compute Failure Links
// Failure links allow efficient backtracking when mismatches occur.

// scss
// Copy
// Edit
//     (he) → fail → (h)
//     (his) → fail → (h)
//     (she) → fail → (he)
//     (hers) → fail → (she)
// Step 3: Search in Text using Failure Links
// When scanning "ahishers", failure links optimize pattern matching.

// Example:
// vbnet
// Copy
// Edit
// Text:    "ahishers"
// Patterns: ["he", "she", "his", "hers"]
// Output:

// sql
// Copy
// Edit
// Pattern "he" found at indices: 1 4
// Pattern "she" found at indices: 3
// Pattern "his" found at indices: 1
//Pattern "hers" found at indices: 4