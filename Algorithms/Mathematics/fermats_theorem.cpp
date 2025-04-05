#include <iostream>
using namespace std;

// Function to compute (base^exp) % mod using Fast Modular Exponentiation
long long fastModExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)  // If exponent is odd, multiply base with result
            result = (result * base) % mod;
        
        base = (base * base) % mod;  // Square the base
        exp /= 2;
    }

    return result;
}

// Function to compute Modular Inverse using Fermat’s Theorem
long long modInverseFermat(long long a, long long p) {
    if (p <= 1) return -1; // Invalid case (p should be prime)
    return fastModExp(a, p - 2, p);
}

// Driver function
int main() {
    long long a = 3, p = 7;
    cout << "Modular inverse of " << a << " under mod " << p << " is: " << modInverseFermat(a, p) << endl;
    return 0;
}
