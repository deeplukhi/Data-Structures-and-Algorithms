#include <iostream>
#include <vector>
using namespace std;

// Function to compute the Longest Common Subsequence (LCS)
int lcs(string X, string Y) {
    int N = X.length(), M = Y.length();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    // Fill DP table
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[N][M]; // Length of LCS
}

// Driver function
int main() {
    string X = "AGGTAB", Y = "GXTXAYB";
    
    cout << "Length of LCS = " << lcs(X, Y) << endl;
    return 0;
}
