// Q3 A Maze
/*
Time limit：1   Memory limit：32M

Description：
Given a N*M maze，where there are T barriers that you cannot pass. Given the coordinates of the original starting point 
and the destination, find out how many ways there are to reach the destination if you can only pass each cell once. You 
can move up, down, to the left ot to the right, and move only one step at a time. It is guaranteed that there is no barrier 
at the starting point.

Input：
The first line: N、M and T. N is the row. M is the column. T is the number of barrier.
The second line: coordinates of the starting point SX,SY. Coordinates of the destination FX,FY。
The next T lines: each contains the coordinates of the barriers.

Output：
the number of ways there are to reach the destination if you can only pass each cell once.

Sample input 1：
2 2 1
1 1 2 2
1 2

Sample output 1：
1

Note：
1≤N,M≤5
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(vector<vector<int>> &maze, int sx, int sy, int fx, int fy, int &count) {
    if (sx >= maze.size() || sy >= maze[0].size() || sx < 0 || sy < 0 || maze[sx][sy] == 1) {
        return;
    }
    if (sx == fx && sy == fy) {
        count++;
        return;
    }
    maze[sx][sy] = 1;
    for (int i = 0; i < 4; i++) {
        int r = sx+dx[i], c = sy+dy[i];
        dfs(maze, r, c, fx, fy, count);
    }
    maze[sx][sy] = 0;
}

int main(void) {
    int n, m, t;
    cin >> n >> m >> t;

    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    sx--;
    sy--;
    fx--;
    fy--;

    vector<vector<int>> maze(n, vector<int> (m, 0));
    while (t) {
        int x, y;
        cin >> x >> y;
        maze[x][y] = 1;
        t--;
    }

    int count = 0;
    dfs(maze, sx, sy, fx, fy, count);
    cout << count;
}