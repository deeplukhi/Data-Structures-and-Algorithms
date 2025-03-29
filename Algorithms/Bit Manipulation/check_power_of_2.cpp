#include <iostream>
using namespace std;

// Function to check if a number is a power of 2
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

// Driver function
int main() {
    int testCases[] = {1, 2, 3, 4, 8, 16, 18, 32, 64, 100};
    
    cout << "Checking power of 2:\n";
    for (int num : testCases) {
        cout << num << " -> " << (isPowerOfTwo(num) ? "Yes" : "No") << endl;
    }
    
    return 0;
}
