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
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        maze.push_back(row);
    }
    maze[0][0] = '1';
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
            if (xx < 0 || yy < 0 || xx >= n || yy >= m || maze[xx][yy] == '1') {
                continue;
            }
            if (xx == n-1 && yy == m-1) {
                cout << count;
                return 0;
            }            
            if (maze[xx][yy] == '0') {
                maze[xx][yy] = '1';
            } else if (found && maze[xx][yy] == ch) {
                continue;
            }
            q.push(point(xx, yy, count));
        }
    }
    cout << "No Solution.";
    return 0;
}