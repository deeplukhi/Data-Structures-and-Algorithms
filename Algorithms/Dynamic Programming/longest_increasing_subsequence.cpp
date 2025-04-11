#include <iostream>
#include <vector>
using namespace std;

// Function to compute the Longest Increasing Subsequence (LIS)
int lis(vector<int>& nums) {
    int N = nums.size();
    vector<int> dp(N, 1); // Initialize LIS values as 1 for all indices

    int maxLength = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) { // Can extend subsequence
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

// Driver function
int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    
    cout << "Length of LIS = " << lis(nums) << endl;
    return 0;
}
