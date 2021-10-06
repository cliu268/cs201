// Q1 Labyrinth
/*
The mouse walks the labyrinth, the labyrinth is the square of the side N, from the upper left corner(entrance)
to the lower right corner (exit), it is not allowed to go back. Compute the length of the shortest path and 
the number of the shortest path (N<15)

Input :
The first line is a positive integer n
Followed by n rows of n numbers (1 or 0) where 0 can pass, 1 can not

Output:
The number of the shortest path
And the length of the shortest path

Sample input:
5
0 0 0 0 0
0 1 1 1 0
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0

Sample output:
1
9

Sample input:
5
0 0 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 0 1 0
0 0 0 0 0

Sample output:
4
9

Sample input:
5
0 0 0 0 0
0 1 1 1 1
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0

Sample output:
1
13
*/
#include <iostream>
#include <vector>
using namespace std;

bool isValidPath(vector<vector<int>> maze, int row, int col) {
    if (row < 0 || col < 0 || row >= maze.size() || col >= maze.size() || maze[row][col] == 1) {
        return false;
    }
    return true;
}

void solve(vector<vector<int>> &maze, int row, int col, int &count, int &length, int &shortest) {
    // for (int i = 0; i < maze.size(); i++) {
    //     for (int j = 0; j < maze.size(); j++) {
    //         cout << maze[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    if (!isValidPath(maze, row, col)) {
        return;
    }

    if (row == maze.size()-1 && col == maze.size()-1) {
        if (length+1 == shortest) {
            count += 1;
        } else if (shortest == 0 || length+1 < shortest) {
            shortest = length+1;
            count = 1;
        }
        return;
    }

    maze[row][col] = 1;
    length += 1;

    solve(maze, row+1, col, count, length, shortest);
    solve(maze, row-1, col, count, length, shortest);
    solve(maze, row, col+1, count, length, shortest);
    solve(maze, row, col-1, count, length, shortest);

    maze[row][col] = 0;
    length -= 1;    
}

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> maze(n);
    for (int i = 0; i < n; i++) {
        vector<int> row(n);
        for (int j = 0; j < n; j++) {
            cin >> row[j];            
        }
        maze[i] = row;
    }
    int count = 0, length = 0, shortest = 0;
    solve(maze, 0, 0, count, length, shortest);
    cout << count << "\n" << shortest << endl;
    return 0;
}