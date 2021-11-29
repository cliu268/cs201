// Q2 WoW
/*
Small A is a small warlock in WoW - World of Warcraft. As a warlock, it is quite shameful not being able to solo a BOSS. 
The so-called solo BOSS is to single-handed defeat the BOSS, so how can Small A with great sense of honor not to do it? 
Now Small A needs to go to the end of the Doom to find the BOSS. Small A looked at the map of Doom that is an N*M 
rectangular maze (N, M<=100) with minions and portals, where 1 means minion blocking the way, 0 means pass, and uppercase 
letters indicate teleport portals. How do the teleport portals work? When you enters the portal A, you'll be immediately 
teleported to another A, and the same for the other letters. The data ensures that each portal has one and only one 
corresponding portal.

The entrance is at the upper left (1,1), but the BOSS is hiding at the bottom right (N,M). small A is very eager to 
complete the solo mission and then he can go to other warriors to show off, so Small A would never waste time on the 
minions by avoiding them, and want to reach BOSS as soon as possible through the portals. How to find the fastest way? 
Of course, programming!

Input:
The first line of 2 data: n m;
The following n lines, m chars per line representing the map of Doom. There are no spaces between the map data. You can 
only go one step at a time, at the direction up, down,left or right. The upper left corner is the entry point and the 
lower right corner is the exit point where the BOSS is located.

Output:
An integer that tells the least steps it takes for Small A find the BOSS. If the small A cannot reach the target, then 
output "No Solution.".

Sample input 1:
3 4
0000
00A0
A000

Sample output 1:
4

Sample input 2:
4 6
010100
01A100
011101
0000A0

Sample output 2:
10

Sample input 3:
4 4
0ADB
CBAE
FFCD
GGE0

Sample output 3:
3

Sample input 4:
4 4
0000
0AB0
0BA1
0010

Sample output 4:
No Solution.

Data range:
For 60% of the data, n, m <= 20
For 100% of the data, n, m <= 100

Hint:
The route for the example input 1 is as follows:
(1, 1) - (2, 1) - (3 ,1)(2, 3) - (2, 4) - (3, 4)
The route for the example input 2 is: 
(1，1）-（2，1）-（3，1）-（4，1）-（4，2）-（4，3）-（4，4）-（4，5）（2，3）-（1，3）-（2，3）（4，5）-（4，6）
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> maze;
struct point {
    int x, y, l;
    point(int a, int b, int c) : x(a), y(b), l(c) {}
};
queue<point> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        maze.push_back(row);
    }
    visited[0][0] = true;
    q.push(point(0, 0, 0));
    while (!q.empty()) {
        point p = q.front();
        int x = p.x;
        int y = p.y;
        int count = p.l;
        q.pop();
        char ch = maze[x][y];
        bool found = false;
        if (ch >= 'A' && ch <= 'Z') {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == x && j == y) continue;
                    if (maze[i][j] == ch) {
                        x = i, y = j;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }     
        }
        count++;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m || maze[xx][yy] == '1' || visited[xx][yy]) {
                continue;
            }
            if (xx == n-1 && yy == m-1) {
                cout << count;
                return 0;
            }    
            visited[xx][yy] = true;
            q.push(point(xx, yy, count));
        }
    }
    cout << "No Solution.";
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// vector<string> board;
// vector<vector<bool>> visited;
// vector<vector<int>> A;
// int dx[4]={1,-1,0,0};
// int dy[4]={0,0,1,-1};
// struct point {
//   int x,y,length;
//   point(int a, int b, int c) : x(a), y(b), length(c) {}
// };

// queue<point> q;
// int ans=0;
// bool broke=false;

// vector<int> check(char a, int x, int y) {
//   // cout<<a<<": "<<x<<" "<<y<<"\n";
//   for (int i=0; i<board.size(); i++) {
//     for (int j=0; j<board[0].size(); j++) {
//       if (board[i][j]==a && !(i==x && j==y)) {
//         // cout<<a<<": "<<i<<" "<<j<<"\n";
//         return {i,j};
//       }
//     }
//   }
// }
// void exploreNeighbors(int x, int y, int length) {
//   length++;
//   // cout<<"exploring (" << x <<"," << y << ") \n";
//   for (int i=0; i<4; i++) {
//     if (x+dx[i]<0 || y+dy[i]<0 || x+dx[i]>=board.size() || y+dy[i]>=board[0].size()) {
//       continue;
//     }
//     if (visited[x+dx[i]][y+dy[i]]==true) {
//       continue;
//     }
//     if (board[x+dx[i]][y+dy[i]]=='1') {
//       continue;
//     }
//     if (x+dx[i]==board.size()-1 && y+dy[i]==board[0].size()-1) {
//       ans=length;
//       broke=true;
//       return;
//     }
//     if (board[x+dx[i]][y+dy[i]]!='0') {
//       vector<int> other=check(board[x+dx[i]][y+dy[i]], x+dx[i], y+dy[i]);
//       q.push(point(other[0], other[1], length));
//       // cout<<"pushing (" << other[0]<<"," << other[1] << ") \n";
//     }
//     else {
//       q.push(point(point(x+dx[i], y+dy[i], length)));
//       // cout<<"pushing (" << x+dx[i]<<"," << y+dy[i] << ") \n";
//     }
//     visited[x+dx[i]][y+dy[i]]=true;
//   }
// }
// void bfs() {
//   int length=0; 
//   q.push(point(0,0,length));
//   while (!q.empty() && broke==false) {
//     point current=q.front();
//     q.pop();
//     exploreNeighbors(current.x, current.y, current.length);
//   }
// }
// int main() {
//   int n,m;
//   cin>>n>>m;
//   for (int i=0; i<n; i++) {
//     string s;
//     cin>>s;
//     board.push_back(s);
//   }
//   for (int i=0; i<n; i++) {
//     vector<bool> row(m);
//     for (int j=0; j<m; j++) {
//       row[j]=false;
//     }
//     visited.push_back(row);
//   }
//   bfs();
//   if (broke==false) {
//     cout<<"No Solution.";
//   }
//   else {
//     cout<<ans;
//   }
// } 
