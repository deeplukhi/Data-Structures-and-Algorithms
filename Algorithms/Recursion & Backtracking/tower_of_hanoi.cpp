//Great! Let's implement **Tower of Hanoi** next. 🏗️🔄  


// ## **📜 `tower_of_hanoi.cpp` (Recursion & Backtracking)**  
// ✔ **Tower of Hanoi** is a **classic recursion problem** involving:  
// - **Three rods**: **Source (A), Auxiliary (B), Destination (C)**  
// - **N disks**, initially stacked on the **Source rod** in decreasing size  
// - **Objective**: Move all disks from **Source → Destination** following these rules:  
//   - **Only one disk can be moved at a time**  
//   - **A larger disk cannot be placed on a smaller disk**  
//   - **Only the top disk of any rod can be moved**  

// ✔ **Time Complexity**: **O(2ⁿ - 1)** (Exponential)  
// ✔ **Space Complexity**: **O(N)** (Recursive stack)  

// ---

// ### **🔹 C++ Implementation of Tower of Hanoi**

#include <iostream>
using namespace std;

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char src, char aux, char dest) {
    if (n == 1) {
        cout << "Move disk 1 from " << src << " to " << dest << endl;
        return;
    }
    
    // Move (n-1) disks from Source to Auxiliary using Destination
    towerOfHanoi(n - 1, src, dest, aux);
    
    // Move the nth disk from Source to Destination
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    
    // Move (n-1) disks from Auxiliary to Destination using Source
    towerOfHanoi(n - 1, aux, src, dest);
}

// Driver function
int main() {
    int n; // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;

    // A = Source, B = Auxiliary, C = Destination
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}



// ## **📌 Explanation**
// 1️⃣ **Move (N-1) disks** from **Source → Auxiliary** using **Destination** as helper.  
// 2️⃣ **Move the largest disk** directly from **Source → Destination**.  
// 3️⃣ **Move (N-1) disks** from **Auxiliary → Destination** using **Source** as helper.  
// 4️⃣ **Repeat recursively** until `n == 1` (base case).  

// ✔ **Minimum moves required**: `2ⁿ - 1` (Exponential growth).  
// ✔ Used in **disk management, recursion problems, and algorithm design.**  

