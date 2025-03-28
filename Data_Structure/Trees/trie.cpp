#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    // Check if any word in Trie starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

int main() {
    Trie trie;
    
    trie.insert("apple");
    trie.insert("app");
    
    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;   // Found
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;     // Found
    cout << "Search 'appl': " << (trie.search("appl") ? "Found" : "Not Found") << endl;   // Not Found
    cout << "Starts with 'app': " << (trie.startsWith("app") ? "Yes" : "No") << endl;     // Yes

    return 0;
}



// Search 'apple': Found
// Search 'app': Found
// Search 'appl': Not Found
// Starts with 'app': Yes
