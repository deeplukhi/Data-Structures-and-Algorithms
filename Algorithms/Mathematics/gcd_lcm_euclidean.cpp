#include <iostream>
using namespace std;

// Function to compute GCD using Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

// Function to compute LCM using GCD
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;  // Avoids integer overflow
}

// Driver function
int main() {
    int a = 36, b = 60;
    
    cout << "GCD of " << a << " and " << b << " = " << gcd(a, b) << endl;
    cout << "LCM of " << a << " and " << b << " = " << lcm(a, b) << endl;

    return 0;
}
