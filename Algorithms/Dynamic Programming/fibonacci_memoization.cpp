#include <iostream>
#include <vector>
using namespace std;

// Function to compute Fibonacci using Memoization
int fibonacci(int n, vector<int>& dp) {
    if (n <= 1) return n; // Base case
    if (dp[n] != -1) return dp[n]; // Return if already computed
    
    return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

// Driver function
int main() {
    int n = 10; // Compute Fibonacci of 10
    vector<int> dp(n + 1, -1); // Memoization array

    cout << "Fibonacci(" << n << ") = " << fibonacci(n, dp) << endl;
    return 0;
}
