#include <iostream>
#include <list>
#include <vector>
using namespace std;


//Hash Table (Separate Chaining)

class HashTable {
private:
    int capacity; // Size of the hash table
    vector<list<pair<int, string>>> table; // Array of linked lists (Separate Chaining)

    // Hash Function (Simple Modulo)
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTable(int size) {
        capacity = size;
        table.resize(capacity);
    }

    // Insert key-value pair
    void insert(int key, string value) {
        int index = hashFunction(key);
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; // Update value if key exists
                return;
            }
        }
        table[index].push_back({key, value}); // Insert new key-value pair
    }

    // Search for a key
    string search(int key) {
        int index = hashFunction(key);
        for (auto &pair : table[index]) {
            if (pair.first == key)
                return pair.second;
        }
        return "Not Found";
    }

    // Remove a key
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove_if([key](const pair<int, string> &p) {
            return p.first == key;
        });
    }

    // Print Hash Table
    void printHashTable() {
        cout << "Hash Table:\n";
        for (int i = 0; i < capacity; i++) {
            cout << i << " -> ";
            for (auto &pair : table[i])
                cout << "[" << pair.first << ": " << pair.second << "] ";
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable(10);

    // Insert key-value pairs
    hashTable.insert(1, "Apple");
    hashTable.insert(2, "Banana");
    hashTable.insert(12, "Cherry"); // Collides with key 2 (12 % 10 == 2)
    hashTable.insert(22, "Mango"); // Collides with key 2 (22 % 10 == 2)

    // Print Hash Table
    hashTable.printHashTable();

    // Search for keys
    cout << "\nSearch for key 2: " << hashTable.search(2) << endl;
    cout << "Search for key 12: " << hashTable.search(12) << endl;
    cout << "Search for key 5: " << hashTable.search(5) << endl;

    // Remove a key
    hashTable.remove(12);
    cout << "\nAfter deleting key 12:\n";
    hashTable.printHashTable();

    return 0;
}
