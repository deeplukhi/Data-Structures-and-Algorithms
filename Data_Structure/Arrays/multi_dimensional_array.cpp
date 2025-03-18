#include <iostream>
using namespace std;

void printMatrix(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Declaration and Initialization
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};

    cout << "Original 2D Array: " << endl;
    printMatrix(matrix, 2, 3);

    // Modifying an element
    matrix[1][2] = 9;
    cout << "After modifying matrix[1][2] to 9: " << endl;
    printMatrix(matrix, 2, 3);

    return 0;
}
