#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> Matrix;
const int MOD = 1e9 + 7;

// Function to multiply two matrices (mod MOD)
Matrix multiply(Matrix& A, Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Function to compute matrix exponentiation (A^exp % MOD)
Matrix matrixExp(Matrix A, long long exp) {
    int n = A.size();
    Matrix result(n, vector<long long>(n, 0));

    // Initialize result as identity matrix
    for (int i = 0; i < n; i++) result[i][i] = 1;

    while (exp > 0) {
        if (exp % 2 == 1) result = multiply(result, A);
        A = multiply(A, A);
        exp /= 2;
    }

    return result;
}

// Driver function
int main() {
    long long n;
    cout << "Enter exponent n: ";
    cin >> n;

    // Example: Fibonacci matrix exponentiation
    Matrix F = {{1, 1}, {1, 0}}; // Transformation matrix for Fibonacci sequence

    if (n == 0) cout << "Fibonacci(0) = 0" << endl;
    else {
        Matrix result = matrixExp(F, n - 1);
        cout << "Fibonacci(" << n << ") = " << result[0][0] << endl;
    }
    
    return 0;
}
