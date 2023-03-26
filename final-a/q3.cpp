// C. Minimum Turns
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6573&fragments=11889&problemId=8121&pattern=0
/*
Description：
Given a matrix, please find the minimum number of turns (change of direction) to get from the start position to the end position, 
if no available path, output -1.

Input：
The first line contains n and m, indicating the number of rows and columns.
Next is the n*m matrix. 0 means you can walk on that tile, 1 means that you cannot.
The last line is the position of the starting point and end point.

Output：
The answer (minimum number of turns).

Sample input
5 7
1 0 0 0 0 1 0
0 0 1 0 1 0 0
0 0 0 0 1 0 1
0 1 1 0 0 0 0
0 0 0 0 1 1 0
1 3 1 7

Sample output
5

Note：
2≤n,m≤100
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> maze;
int a=0, answer=-1;
int n,m;
int sx,sy, ex, ey;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void floodfill(int x, int y, int d){

    if (x<0 || x>=n || y<0 || y>=m){
        return;
    }
    
    if (maze[x][y] == 1 || maze[x][y] == -1){
        return;
    }

    if (x == ex && y == ey) {
        if (answer != -1) {
            answer = min(answer, a);
        } else {
            answer = a;
        }
        return;
    }

    maze[x][y]=-1;
    
    for (int i = 0; i < 4; i++) {
        if (d != i && d != -1) a++;
        floodfill(x+dx[i], y+dy[i], i); 
        if (d != i && d != -1) a--;
    }

    maze[x][y]=0;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        vector<int> row(m);
        for(int j=0; j<m; j++){
            cin >> row[j];
        }
        maze.push_back(row);
    }

    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;

    floodfill(sx, sy, -1);

    cout << answer << endl;
}