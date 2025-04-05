#include <iostream>
using namespace std;

// Function to compute (base^exp) % mod using Fast Exponentiation
long long fastModExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;  // Reduce base if greater than mod

    while (exp > 0) {
        if (exp % 2 == 1)  // If exponent is odd, multiply base with result
            result = (result * base) % mod;

        base = (base * base) % mod;  // Square the base
        exp /= 2;
    }

    return result;
}

// Driver function
int main() {
    long long base = 3, exp = 13, mod = 7;
    cout << base << "^" << exp << " % " << mod << " = " << fastModExp(base, exp, mod) << endl;
    return 0;
}
