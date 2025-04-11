#include <iostream>
#include <vector>
using namespace std;

// Function to compute the edit distance between two strings
int editDistance(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize base cases
    for (int i = 0; i <= n; i++) dp[i][0] = i; // Cost of deleting all characters
    for (int j = 0; j <= m; j++) dp[0][j] = j; // Cost of inserting all characters

    // Fill DP table using bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No cost if characters match
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],    // Delete
                                    dp[i][j - 1],    // Insert
                                    dp[i - 1][j - 1] // Replace
                                   });
            }
        }
    }

    return dp[n][m]; // Minimum edit distance
}

// Driver function
int main() {
    string s1 = "horse", s2 = "ros";
    
    cout << "Minimum edit distance = " << editDistance(s1, s2) << endl;
    return 0;
}
