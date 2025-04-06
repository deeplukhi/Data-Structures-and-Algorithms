#include <iostream>
#include <vector>
using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array
vector<int> computeLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;  // Length of previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Move to previous LPS
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP Algorithm for Pattern Matching
vector<int> kmpSearch(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> occurrences;
    
    if (m > n) return occurrences;

    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0; // i -> text index, j -> pattern index

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++, j++;
        }

        if (j == m) {
            occurrences.push_back(i - j); // Found match
            j = lps[j - 1]; // Move j to previous LPS
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1]; // Move j to previous LPS
            } else {
                i++;
            }
        }
    }

    return occurrences;
}

// Driver function
int main() {
    string text = "ababcababcababc";
    string pattern = "ababc";

    vector<int> result = kmpSearch(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : result) cout << index << " ";
    cout << endl;

    return 0;
}
