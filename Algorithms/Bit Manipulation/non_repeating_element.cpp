#include <iostream>
#include <vector>
using namespace std;

// Function to find two non-repeating elements in an array
void findUniqueElements(const vector<int>& arr) {
    int xorAll = 0;
    for (int num : arr)
        xorAll ^= num;  // XOR all elements

    // Find rightmost set bit (differs between the two unique numbers)
    int diffBit = xorAll & -xorAll;

    int x = 0, y = 0;
    for (int num : arr) {
        if (num & diffBit)  // Group 1 (bit set)
            x ^= num;
        else  // Group 2 (bit not set)
            y ^= num;
    }

    cout << "Two unique elements: " << x << " and " << y << endl;
}

// Driver function
int main() {
    vector<int> arr = {4, 1, 2, 1, 2, 5, 4, 7};
    
    findUniqueElements(arr);
    
    return 0;
}
