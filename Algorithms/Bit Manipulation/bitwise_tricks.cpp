#include <iostream>
#include <vector>
using namespace std;

// 1️⃣ Check if a number is even or odd
bool isEven(int n) {
    return (n & 1) == 0;
}

// 2️⃣ Multiply & divide by 2 using left/right shift
int multiplyBy2(int n) { return n << 1; } // n * 2
int divideBy2(int n) { return n >> 1; }   // n / 2

// 3️⃣ Swap two numbers without a temp variable
void swapNumbers(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

// 4️⃣ Toggle a bit at position `pos`
int toggleBit(int n, int pos) {
    return n ^ (1 << pos);
}

// 5️⃣ Set and clear a bit at position `pos`
int setBit(int n, int pos) {
    return n | (1 << pos);
}
int clearBit(int n, int pos) {
    return n & ~(1 << pos);
}

// 6️⃣ Find the only non-repeating element in an array using XOR
int findUniqueElement(const vector<int>& arr) {
    int result = 0;
    for (int num : arr)
        result ^= num;
    return result;
}

// Driver function
int main() {
    int x = 5, y = 7;
    cout << "Is " << x << " even? " << (isEven(x) ? "Yes" : "No") << endl;
    cout << "Multiply " << x << " by 2: " << multiplyBy2(x) << endl;
    cout << "Divide " << x << " by 2: " << divideBy2(x) << endl;

    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapNumbers(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    int num = 10; // 1010 in binary
    int pos = 1;
    cout << "Toggle bit at pos " << pos << ": " << toggleBit(num, pos) << endl;
    cout << "Set bit at pos " << pos << ": " << setBit(num, pos) << endl;
    cout << "Clear bit at pos " << pos << ": " << clearBit(num, pos) << endl;

    vector<int> arr = {4, 1, 2, 1, 2, 4, 7};
    cout << "Unique element in array: " << findUniqueElement(arr) << endl;

    return 0;
}



// ✔ Algorithm: Common bitwise operations for fast computations.
// ✔ Tricks Covered:
// 1️⃣ Check if a number is even/odd
// 2️⃣ Multiply/divide by 2 using shifts
// 3️⃣ Swap two numbers without a temp variable
// 4️⃣ Toggle a bit at a specific position
// 5️⃣ Set and clear a bit
// 6️⃣ Find the only non-repeating element in an array (XOR trick)
// ✔ Time Complexity: O(1) per operation
// ✔ Space Complexity: O(1)

// 📌 Explanation
// 1️⃣ Even/Odd Check: n & 1 → If the last bit is 1, it's odd.
// 2️⃣ Bitwise Multiply/Divide:

// n << 1 → Multiply by 2
// n >> 1 → Divide by 2
// 3️⃣ XOR Swap Trick:
// a ^= b; b ^= a; a ^= b; swaps a and b without extra space.
// 4️⃣ Toggle, Set, Clear Bit:
// n ^ (1 << pos): Flip the bit at pos.
// n | (1 << pos): Set bit at pos to 1.
// n & ~(1 << pos): Clear bit at pos to 0.
// 5️⃣ Finding Unique Element:
// x ^ x = 0 (XOR cancels out duplicates).
// x ^ 0 = x (XOR with 0 keeps the number).
// Applying XOR on an array where all numbers appear twice except one gives the unique element.
