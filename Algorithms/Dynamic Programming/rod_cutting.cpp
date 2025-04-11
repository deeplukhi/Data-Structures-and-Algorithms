#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum profit for rod cutting
int rodCutting(vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);

    // Build the DP table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
        }
    }

    return dp[n]; // Maximum obtainable price
}

// Driver function
int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; // Prices for rod lengths 1 to 8
    int n = price.size();

    cout << "Maximum obtainable price = " << rodCutting(price, n) << endl;
    return 0;
}
