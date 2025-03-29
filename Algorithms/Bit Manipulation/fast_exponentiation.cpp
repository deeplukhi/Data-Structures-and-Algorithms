#include <iostream>
using namespace std;

// Function for Fast Exponentiation (a^b)
long long fastExpo(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)  // If the last bit of b is set, multiply `res` with `a`
            res *= a;
        a *= a;  // Square `a`
        b >>= 1; // Right shift `b` (divide by 2)
    }
    return res;
}

// Function for Modular Exponentiation (a^b % M)
long long modExpo(long long a, long long b, long long M) {
    long long res = 1;
    a %= M;  // Reduce `a` initially to avoid overflow
    while (b > 0) {
        if (b & 1)  // If the last bit of b is set, multiply `res` with `a`
            res = (res * a) % M;
        a = (a * a) % M;  // Square `a`
        b >>= 1; // Right shift `b` (divide by 2)
    }
    return res;
}

// Driver function
int main() {
    long long a = 2, b = 10, M = 1e9 + 7;

    cout << "Fast Exponentiation: " << a << "^" << b << " = " << fastExpo(a, b) << endl;
    cout << "Modular Exponentiation: " << a << "^" << b << " % " << M << " = " << modExpo(a, b, M) << endl;

    return 0;
}



// ✔ Algorithm: Compute a^b (mod M if required) efficiently using Exponentiation by Squaring.
// ✔ Approach:
// 1️⃣ If b is even, a^b = (a^(b/2))^2.
// 2️⃣ If b is odd, a^b = a × (a^(b-1)).
// 3️⃣ Use bitwise shifts to divide b by 2.
// 4️⃣ Modular exponentiation ((a^b) % M) can be used for large numbers.
// ✔ Time Complexity: O(log B)
// ✔ Space Complexity: O(1)



// 📌 Explanation
// Example Walkthrough
// Compute 2^10:
// 1️⃣ Binary Representation of 10 → 1010
// 2️⃣ Break it into powers:

// Copy
// Edit
// 2^10 = (2^8) * (2^2)
// 3️⃣ Compute using bitwise shifts:

// 2^8 = (2^4)^2
// 2^4 = (2^2)^2
// 2^2 = (2^1)^2
// 2^1 = 2
// Example with Modular Exponentiation
// Compute 2^10 % 1000000007:

// yaml
// Copy
// Edit
// 2^10 = 1024
// 1024 % 1000000007 = 1024
