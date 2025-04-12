#include <iostream>
#include <vector>
using namespace std;

// Function to add two matrices
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to subtract two matrices
vector<vector<int>> subMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's Matrix Multiplication
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize)),
                        A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize)),
                        B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize)),
                        B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));

    // Dividing matrices into 4 sub-matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];                 B11[i][j] = B[i][j];
            A12[i][j] = A[i][j + newSize];        B12[i][j] = B[i][j + newSize];
            A21[i][j] = A[i + newSize][j];        B21[i][j] = B[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize]; B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculating the 7 products
    vector<vector<int>> P1 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> P2 = strassen(addMatrix(A21, A22), B11);
    vector<vector<int>> P3 = strassen(A11, subMatrix(B12, B22));
    vector<vector<int>> P4 = strassen(A22, subMatrix(B21, B11));
    vector<vector<int>> P5 = strassen(addMatrix(A11, A12), B22);
    vector<vector<int>> P6 = strassen(subMatrix(A21, A11), addMatrix(B11, B12));
    vector<vector<int>> P7 = strassen(subMatrix(A12, A22), addMatrix(B21, B22));

    // Combining the results into the final matrix
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = P1[i][j] + P4[i][j] - P5[i][j] + P7[i][j];
            C[i][j + newSize] = P3[i][j] + P5[i][j];
            C[i + newSize][j] = P2[i][j] + P4[i][j];
            C[i + newSize][j + newSize] = P1[i][j] - P2[i][j] + P3[i][j] + P6[i][j];
        }
    }

    return C;
}

// Driver function
int main() {
    int n;
    cout << "Enter the size of the matrix (must be power of 2): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));

    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    vector<vector<int>> result = strassen(A, B);

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}
