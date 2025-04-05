#include <iostream>
#include <vector>
using namespace std;

// Function to compute GCD and modular inverse using Extended Euclidean Algorithm
long long modInverse(long long a, long long m) {
    long long m0 = m, y = 0, x = 1;
    if (m == 1) return 0;

    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    return (x + m0) % m0;
}

// Function to solve system of congruences using CRT
long long chineseRemainder(vector<int>& num, vector<int>& rem) {
    long long prod = 1, result = 0;
    int k = num.size();

    // Compute product of all moduli
    for (int i = 0; i < k; i++)
        prod *= num[i];

    // Compute result using CRT formula
    for (int i = 0; i < k; i++) {
        long long Mi = prod / num[i];  // Compute Mᵢ
        long long yi = modInverse(Mi, num[i]);  // Compute yᵢ = Mᵢ⁻¹ mod mᵢ
        result = (result + rem[i] * Mi * yi) % prod;
    }

    return result;
}

// Driver function
int main() {
    vector<int> num = {3, 5, 7};  // Moduli
    vector<int> rem = {2, 3, 2};  // Remainders

    cout << "The solution x is: " << chineseRemainder(num, rem) << endl;
    return 0;
}
