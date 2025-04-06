#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int BASE = 31;

// Function to compute hash value of a string
long long computeHash(const string& s, int len) {
    long long hashValue = 0, power = 1;
    for (int i = 0; i < len; i++) {
        hashValue = (hashValue + (s[i] - 'a' + 1) * power) % MOD;
        power = (power * BASE) % MOD;
    }
    return hashValue;
}

// Rabin-Karp algorithm for pattern matching
vector<int> rabinKarp(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> occurrences;

    if (m > n) return occurrences;

    long long patternHash = computeHash(pattern, m);
    long long textHash = computeHash(text, m);

    long long power = 1;
    for (int i = 0; i < m - 1; i++) 
        power = (power * BASE) % MOD; // Precompute power for rolling hash

    // Sliding window: compare hash values and check exact match if needed
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) { // Possible match, verify characters
            if (text.substr(i, m) == pattern)
                occurrences.push_back(i);
        }

        // Compute next window hash (Rolling Hash)
        if (i < n - m) {
            textHash = (textHash - (text[i] - 'a' + 1) + MOD) % MOD;
            textHash = (textHash * BASE) % MOD;
            textHash = (textHash + (text[i + m] - 'a' + 1) * power) % MOD;
        }
    }

    return occurrences;
}

// Driver function
int main() {
    string text = "abracadabra";
    string pattern = "abra";

    vector<int> result = rabinKarp(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : result) cout << index << " ";
    cout << endl;

    return 0;
}
