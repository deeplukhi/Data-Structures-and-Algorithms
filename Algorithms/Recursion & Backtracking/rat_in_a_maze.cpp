#include <iostream>
#include <vector>
using namespace std;

// Directions (Down, Left, Right, Up)
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dir[] = {'D', 'L', 'R', 'U'}; // Move direction characters

// Function to check if the move is valid
bool isSafe(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &visited, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && visited[x][y] == 0);
}

// Recursive function to find all paths
void findPaths(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &visited, string path, int n) {
    if (x == n - 1 && y == n - 1) { // Reached destination
        cout << path << endl;
        return;
    }

    // Mark current cell as visited
    visited[x][y] = 1;

    // Try all 4 possible moves
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i], newY = y + dy[i];
        if (isSafe(newX, newY, maze, visited, n)) {
            findPaths(newX, newY, maze, visited, path + dir[i], n);
        }
    }

    // Backtrack (unmark current cell)
    visited[x][y] = 0;
}

// Driver function
int main() {
    int n;
    cout << "Enter the size of the maze (N x N): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));

    cout << "Enter the maze matrix (0 for wall, 1 for open path):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    vector<vector<int>> visited(n, vector<int>(n, 0));

    cout << "Possible paths: \n";
    if (maze[0][0] == 1)
        findPaths(0, 0, maze, visited, "", n);
    else
        cout << "No path possible!\n";

    return 0;
}
