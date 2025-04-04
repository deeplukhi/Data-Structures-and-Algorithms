#include <iostream>
#include <vector>
using namespace std;

// Function to check if a subset with given sum exists
bool subsetSum(vector<int>& nums, int n, int target) {
    // Base cases
    if (target == 0) return true; // Found a subset with the required sum
    if (n == 0) return false; // No elements left to form the subset

    // If the last element is greater than target, ignore it
    if (nums[n - 1] > target)
        return subsetSum(nums, n - 1, target);

    // Two cases: (1) include nums[n-1] or (2) exclude it
    return subsetSum(nums, n - 1, target) || subsetSum(nums, n - 1, target - nums[n - 1]);
}

// Driver function
int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;

    if (subsetSum(nums, nums.size(), target))
        cout << "Subset with sum " << target << " exists!\n";
    else
        cout << "No subset with sum " << target << " found.\n";

    return 0;
}
