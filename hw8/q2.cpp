// Q2 Wondering Cow
/*
Sapce：32M
Description:
Cows walk in a grassland partioned into N rows and M coloumns (2 <= N <= 100; 2 <= M <= 100), trying to find the place with 
best grass.  Farmer John at a certain time saw Bessie (name of a cow) at spot (R1, C1). After T seconds (0 < T <= 15) John 
meets Bessie at (R2,C2) again. John is not sure if Bessie has been (R2, C2) druing that T seconds already. He is only sure 
that Bessie is now at (R2, C2). Let assume S as the total path between (R1, C1) and (R2, C2) in the past T seconds. John 
wish to have a program to compute the value of S.
The cow moves 1 unit (distance) every second, either in horizontal or vertical direction and will never stay in the same 
place without moving. Of course the cow cannot go to the spots where there are trees, nor she move out of the grassland.
Now you have a map of the grassland, in which '.' means normal spots (flat area) and '*' indicates where trees are. Now 
please find out all possible paths from (R1, C1) to (R2, C2) a cow could take in T seconds.

Input:
1st line has 3 numbers seperated by spaces: N, M, T.
2nd to N+1st lines: i+1st line has M characters ('.' or '*'). These characrters describe the conditions ("normal" or "has 
tree") of each spot on row i. 
N+2nd line has 4 numbers seperated by spaces: R1, C1, R2, C2

Output
One line contain the value of S (as descibed in the "description" part abive).

Sample input 1：
4 5 6
...*.
...*.
.....
.....
1 3 1 5

Sample output 1：
1

Sample input 2:
20 20 15
..*.......**...*....
................**..
....*............*..
....**............*.
..*.................
.....*..............
.............*.**...
........*..*......**
.............*.*.*..
.....*........*.....
.*..*....*..........
*................*..
***.................
.........*....*.....
.......**...........
...........**.....*.
..*.*...............
....*......*........
....................
........*.......*...
18 11 18 10

Sample output 2:
14396412

Note：
2<=n,m<=100
0
*/
// Reference this: https://www.codeleading.com/article/7312839084/ to save intermediate steps to save time
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point {
    int x, y, l;
    point(int a, int b, int c) : x(a), y(b), l(c) {}
};
vector<string> map;
queue<point> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(point p) {
    if (p.x < 0 || p.y < 0 || p.x >= map.size() || p.y >= map[0].size() || map[p.x][p.y] == '*') {
        return false;
    } 
    return true;
}

int main(void) {
    int n,m,t,r1,c1,r2,c2;
    cin >> n >> m >> t;
    vector<vector<vector<int>>> ans(n, vector<vector<int>> (m, vector<int> (t+1, 0)));
    string row;
    for (int i = 0; i < n; i++) {
        cin >> row;
        map.push_back(row);
    }
    cin >> r1 >> c1 >> r2 >> c2;
    q.push(point(r1-1, c1-1, 0));
    ans[r1-1][c1-1][0] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int l = q.front().l;
        q.pop();
        // if (l == t) {
        //     if (x == r2-1 && y == c2-1) {
        //         ans++;
        //     }
        //     continue;
        // }
        for (int i = 0; i < 4; i++) {
            if (!isValid(point(x+dx[i], y+dy[i], l+1))) {
                continue;
            }            
            if (ans[x+dx[i]][y+dy[i]][l+1] == 0) { // next point has not been visited
                q.push(point(x+dx[i], y+dy[i], l+1));
            }
            ans[x+dx[i]][y+dy[i]][l+1] += ans[x][y][l];
        }
    }
    cout << ans[r2-1][c2-1][t];
    return 0;
}


// Dynamic Programming.. super smart!! found it here https://www.bbsmax.com/A/6pdDLyakdw/
// #include <iostream>
// using namespace std;
// int map[101][101],f[101][101][16];
// int n,m,t,i,j,k,r1,c1,r2,c2;
// char s[101];
// int main() {
//   cin >> n >> m >> t;
//   for(i=1;i<=n;i++) {
//     scanf("%s",s);
//   	for(j=0;j<m;j++) {
//   	  if(s[j]=='.') {
//         map[i][j+1]=1;
//       }
//     }
//   }
//   scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
//   f[r1][c1][0]=1;
//   for(k=1;k<=t;k++) {
//     for(i=1;i<=n;i++) {
//       for(j=1;j<=m;j++) {
//   	    if(map[i][j]) {
// 	        f[i][j][k]=f[i-1][j][k-1]+f[i+1][j][k-1]+f[i][j-1][k-1]+f[i][j+1][k-1];
//         }
//       }
//     }
//   }
//   printf("%d",f[r2][c2][t]);
//   return 0;
// }