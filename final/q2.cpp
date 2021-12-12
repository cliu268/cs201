/* Q2 Flood
Farmer John has a NxN square field. The field was divided into 1x1 grids. Some grids is lower than the ground 
level. There is a faucet located at row number x and column number y. One day John forgot to turn off the 
faucet, how many grids are going to be flooded?

Input:
First line: one number N represents the size of the field
The following N lines represents the NxN grids. 
'-' is the ground level grid.
'_' is the lower-than-ground-level grid.
* is where the faucet is.
Faucet grid will be flooded too.

Output:
One number represents how many grids will be flooded.

Sample input:
4
-_-*
---_
_---
_---

Sample output:
2
*/
// #include <bits/stdc++.h>
// using namespace std;
 
// vector<string> board;
// vector<vector<bool>> visited;
// int counter=0;
// int dx[4]={1,-1,0,0};
// int dy[4]={0,0,1,-1};
// void dfs(int x, int y) {
//   if (x<0 || y<0 || x>=board.size() || y>=board.size()) {
//     return;
//   }
//   if (visited[x][y]) {
//     return;
//   }
//   if (board[x][y]=='-') {
//     return;
//   }
//   counter++;
//   visited[x][y]=true;
//   for (int i=0; i<4; i++) {
//     dfs(x+dx[i], y+dy[i]);
//   }
// }
// int main() {
//   int n; cin>>n;
//   for (int i=0; i<n; i++) {
//     string s; cin>>s;
//     board.push_back(s);
//   }
//   bool broke=false;
//   for (int i=0; i<n; i++) {
//     vector<bool> row(n, false);
//     visited.push_back(row);
//   }
//   for (int i=0; i<n; i++) {
//     for (int j=0; j<n; j++) {
//       if (board[i][j]=='*') {
//         dfs(i,j);
//         broke=true;
//         break;
//       }
//     }
//     if (broke) {break;}
//   }
//   cout<<counter;
// }

#include <iostream>
#include <vector>
using namespace std;

vector<string> field;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;
int ans = 0;

void dfs(int sx, int sy) {
    for (int i = 0; i < 4; i++) {
        int x = sx + dx[i], y = sy + dy[i];
        if (x < 0 || y < 0 || x >= n || y >= n || field[x][y] == '-') {
            continue;
        }
        field[x][y] = '-';
        ans++;
        dfs(x, y);
    }
}

int main(void) {
    cin >> n;
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n && sx == -1 && sy == -1; j++) {
            if (row[j] == '*') {
                sx = i, sy = j;
            }
        }
        field.push_back(row);
    }
    field[sx][sy] = '-';
    ans++;    
    dfs(sx, sy);
    cout << ans;
}