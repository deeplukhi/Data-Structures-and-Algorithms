#include <iostream>
#include <vector>
using namespace std;

// Function to find all prime numbers up to N using Sieve of Eratosthenes
void sieve(int N) {
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false; // Mark all multiples of i as non-prime
            }
        }
    }

    cout << "Prime numbers up to " << N << ": ";
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << endl;
}

// Driver function
int main() {
    int N = 50;
    sieve(N);
    return 0;
}
