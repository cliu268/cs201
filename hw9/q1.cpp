// Q1 Knight Moving
/*
Time Limit：0.2s   Memory Limit：32M 

Description
Please calculate the least steps a knight moves from one position to another on a n*n chessboard.

Input
The first line is an integer n, representing a n*n chess board (x, y is 0 to n-1). 1<=n<=300
The next two lines, each line contains two integers representing the start position and the end position. 

Output
An integer

Sample Input
100
0 0
30 50

​Sample Output
28
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point {
    int x, y, l;
    point(int a, int b, int c) : x(a), y(b), l(c) {}
};
queue<point> q;
// 8 ways to traverse
int dirx[8] = {1, 2, -1, -2, 1, -2, -1, 2};
int diry[8] = {2, 1, -2, -1, -2, 1, 2, -1};

int main(void) {
    int n, sx, sy, ex, ey;
    cin >> n >> sx >> sy >> ex >> ey;
    vector<vector<int>> board(n, vector<int> (n, -1));
    board[sx][sy] = 0;
    q.push(point(sx, sy, 0));
    while (!q.empty()) {
        point p = q.front();
        int x = p.x;
        int y = p.y;
        int count = p.l;
        q.pop();
        if (x == ex && y == ey) {
            break;
        }
        count++;
        for (int i = 0; i < 8; i++) {
            int nx = x+dirx[i], ny = y+diry[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && board[nx][ny] == -1) {
                board[nx][ny] = count;
                q.push(point(nx, ny, count));
            }
        }
    }
    cout << board[ex][ey];
    return 0;
}