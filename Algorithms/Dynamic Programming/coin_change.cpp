#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to compute the minimum number of coins required
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX); 
    dp[0] = 0; // Base case: 0 coins needed for amount 0

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            if (dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount]; // Return -1 if not possible
}

// Driver function
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    
    int result = coinChange(coins, amount);
    if (result != -1)
        cout << "Minimum coins required = " << result << endl;
    else
        cout << "No solution possible!" << endl;

    return 0;
}
