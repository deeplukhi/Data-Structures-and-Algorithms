#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to build Suffix Array using O(N log N) approach
vector<int> buildSuffixArray(const string& s) {
    int n = s.size();
    vector<int> suffixArray(n), rank(n), temp(n);

    // Initial ranking based on first character
    for (int i = 0; i < n; i++) {
        suffixArray[i] = i;
        rank[i] = s[i];
    }

    for (int k = 1; k < n; k *= 2) {
        auto comparator = [&](int a, int b) {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            int ra = (a + k < n) ? rank[a + k] : -1;
            int rb = (b + k < n) ? rank[b + k] : -1;
            return ra < rb;
        };

        sort(suffixArray.begin(), suffixArray.end(), comparator);

        temp[suffixArray[0]] = 0;
        for (int i = 1; i < n; i++) {
            temp[suffixArray[i]] = temp[suffixArray[i - 1]] + (comparator(suffixArray[i - 1], suffixArray[i]) ? 1 : 0);
        }
        rank = temp;
    }
    return suffixArray;
}

// Function to build LCP Array
vector<int> buildLCPArray(const string& s, const vector<int>& suffixArray) {
    int n = s.size();
    vector<int> rank(n), lcp(n, 0);

    for (int i = 0; i < n; i++) rank[suffixArray[i]] = i;

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = suffixArray[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }
    return lcp;
}

// Driver function
int main() {
    string text = "banana";

    vector<int> suffixArray = buildSuffixArray(text);
    vector<int> lcpArray = buildLCPArray(text, suffixArray);

    cout << "Suffix Array: ";
    for (int i : suffixArray) cout << i << " ";
    cout << endl;

    cout << "LCP Array: ";
    for (int i : lcpArray) cout << i << " ";
    cout << endl;

    return 0;
}
