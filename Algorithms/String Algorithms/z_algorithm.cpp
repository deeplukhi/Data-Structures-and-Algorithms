#include <iostream>
#include <vector>
using namespace std;

// Function to compute the Z-array
vector<int> computeZ(const string& s) {
    int n = s.size();
    vector<int> Z(n, 0);
    int L = 0, R = 0; // Z-box boundaries

    for (int i = 1; i < n; i++) {
        if (i <= R) {
            Z[i] = min(R - i + 1, Z[i - L]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] - 1 > R) {
            L = i, R = i + Z[i] - 1;
        }
    }
    return Z;
}

// Z Algorithm for Pattern Matching
vector<int> zAlgorithmSearch(const string& text, const string& pattern) {
    string combined = pattern + "$" + text;
    vector<int> Z = computeZ(combined);
    vector<int> occurrences;
    int m = pattern.size();

    for (int i = m + 1; i < Z.size(); i++) {
        if (Z[i] == m) {
            occurrences.push_back(i - m - 1);
        }
    }

    return occurrences;
}

// Driver function
int main() {
    string text = "ababcababcababc";
    string pattern = "ababc";

    vector<int> result = zAlgorithmSearch(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : result) cout << index << " ";
    cout << endl;

    return 0;
}
