#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack using Bottom-Up DP
int knapsack(int W, vector<int>& weights, vector<int>& values, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[N][W]; // Maximum value for given capacity
}

// Driver function
int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50; // Knapsack capacity
    int N = values.size();

    cout << "Maximum Value in Knapsack = " << knapsack(W, weights, values, N) << endl;
    return 0;
}
