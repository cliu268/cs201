// Q2 01 Maze
/*
Description：
There is a n×n maze of characters 0 and 1. If you are in 0, then you can move to one of the four adjacent 
cells with 1 in it. If you are in 1, then you can move to one of the four adjacent cells with 0 in it.  
Given the maze, find out how many cells you can move into (including the original cell).

input：
The first line contains two positive integers n, m.
The next n lines, each line contains n characters (0 or 1, with no space in between)
The next m lines, each contains two positive integers i and j (separated by space), which means the cell in 
the i-th row and the j-th column (the starting point).

output：
m lines，output the answer for each inquiry.

sample input 1：
2 2
01
10
1 1
2 2

sample output 1：
4
4

sample input 2：
5 3
01001
10101
00111
11010
01010
1 1
3 3
5 5

sample output 2：
16
7
16

sample input 3：
3 2
010
101
001
1 1
3 3

sample output 3：
7
2
Note：
For 100% data, n <= 1000, m <= 100000
*/
#include <iostream>
#include <vector>
using namespace std;

void printMaze(vector<vector<char>> maze) {
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze.size(); j++) {
            cout << maze[i][j];
        }
        cout << "\n";
    }
}

bool isValid(vector<vector<char>> maze, int row, int col, char src) {
    if (row < 0 || col < 0 || row >= maze.size() || col >= maze.size() || 
        maze[row][col] == '*' || maze[row][col] == src) {
        return false;
    }
    return true;
}

void solve(vector<vector<char>> &maze, int &count, int sr, int sc, char src) {
    if (!isValid(maze, sr, sc, src)) {
        return;
    }

    char src2 = maze[sr][sc];
    maze[sr][sc] = '*';
    count++;

    solve(maze, count, sr+1, sc, src2);
    solve(maze, count, sr-1, sc, src2);
    solve(maze, count, sr, sc+1, src2);
    solve(maze, count, sr, sc-1, src2);

    return;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> maze(n);
    for (int i = 0; i < n; i++) {
        vector<char> row(n);
        for (int x = 0; x < n; x++) {
            cin >> row[x];
        }
        maze[i] = row;
    }

    vector<vector<int>> sp(m);
    for (int j = 0; j < m; j++) {
        vector<int> point(2);
        cin >> point[0] >> point[1];
        sp[j] = point;
    }

    for (int k = 0; k < m; k++) {
        vector<vector<char>> maze2 = maze;
        int count = 0;
        char src = ' ';
        solve(maze2, count, sp[k][0]-1, sp[k][1]-1, src);
        cout << count << "\n";
        // printMaze(maze);
        // cout << "**********************" << "\n";
        // printMaze(maze2);
    }
    return 0;    
}