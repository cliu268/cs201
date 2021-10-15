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
#include <queue>
using namespace std;

vector<string> maze;
vector<vector<bool>> visited;
queue<int> ansx, ansy;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve(int &count, int sr, int sc) {
    visited[sr][sc] = true;
    ansx.push(sr);
    ansy.push(sc);
    count++;
    for (int i = 0; i < 4; i++) {
        int x = sr+dx[i], y = sc+dy[i];          
        if (x<0 || y<0 || x>=maze.size() || y>=maze.size()) continue;      
        if (maze[x][y] == maze[sr][sc] || visited[x][y]) continue;  
        solve(count, sr+dx[i], sc+dy[i]);
    }
    return;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;        
        maze.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        vector<bool> row(n, false);
        visited.push_back(row);
    }
    int size = m%2 == 1 ? m/2+1 : m/2;
    vector<vector<int>> sp(size);
    vector<int> point(2);    
    for (int j = 0; j < size-1; j++) {
        cin >> point[0] >> point[1];
        sp[j] = point;
    }
    if (m%2 == 1) {
        cin >> point[0];
        point[1] = sp[size-2][1];
        sp[size-1] = point;
    } else {
        cin >> point[0] >> point[1];
        sp[size-1] = point;
    }    
    // create an answer vector to store all answers
    // this is so you compute ALL cells on the same path just once
    vector<vector<int>> answer(n, vector<int> (n, 0));
    for (int k = 0; k < size; k++) {
        int x=sp[k][0]-1, y=sp[k][1]-1;
        if (answer[x][y] > 0) { // already have an answer, no need to solve again
            cout << answer[x][y] << "\n";
            continue;
        }
        int count = 0;
        solve(count, x, y);
        cout << count << "\n";
        while (!ansx.empty()) {
            int x = ansx.front();
            int y = ansy.front();
            answer[x][y] = count;
            ansx.pop();                 
            ansy.pop();
        }
    }
    for (int k = size; k < m; k++) {
        cout << answer[sp[size-1][0]-1][sp[size-1][1]-1] << "\n";
    }        
    return 0;    
}