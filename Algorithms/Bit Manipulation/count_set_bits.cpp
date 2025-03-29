#include <iostream>
#include <bitset>
using namespace std;

// Function to count set bits using Brian Kernighan’s Algorithm
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // Removes the lowest set bit
        count++;
    }
    return count;
}

// Driver function
int main() {
    int testCases[] = {0, 1, 2, 3, 4, 7, 8, 15, 16, 31};
    
    cout << "Counting set bits:\n";
    for (int num : testCases) {
        cout << num << " (" << bitset<5>(num) << ") -> " << countSetBits(num) << " set bits" << endl;
    }
    
    return 0;
}
