// Q4 KFC Date
/*
Time Limit：0.2s   Memory Limit：32M

Description:
The summer holiday is coming. You and your friend plan to eat KFC. But in the map there are many KFC, so you should 
come up with a way to choose one.The way is:Calculate the journey from you to one KFC,and from your friend to this KFC,
if the sum is the least one among all the KFC,then you and your friend would choose.each step you can only take one of 
4 directions(up,down,left,right).

Input
The first line contains two integers n,m
The next n lines,each line input m characters represent the map. 1<=n,m<=200
'@' is your position
'#' is obstacle
'.' means there is a way you can go
'F' means KFC
'&' means the position of your friend.
'.','F','@' and '&',all these position you can go through.

Output
If you can find a way to get some KFC,output the least journey you and your friend cost,else,output "Meeting cancelled"

Sample Input1
4 4 
@.#F 
.... 
.#.. 
F..&

​Sample Output1
6
 
Sample Input2
4 4 
&.#F 
.... 
.#.. 
F#.@

​Sample Output2
8
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> maze;
struct point {
    int x, y, mc; 
    point(int a, int b, int c) : x(a), y(b), mc(c) {}
};
queue<point> q;
vector<point> kfc;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    int n, m;
    cin >> n >> m;
    int mx, my, fx, fy, answer = 0;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            if (row[j] == '@') {
                mx = i, my = j;
            } else if (row[j] == '&') {
                fx = i, fy = j;
            }
        }
        maze.push_back(row);
    }
    vector<vector<bool>> v(n, vector<bool>(m, false));
    // bfs from my home
    v[mx][my] = true;
    q.push(point(mx, my, 0));
    while (!q.empty()) {
        point p = q.front();
        int x = p.x;
        int y = p.y;
        int count = p.mc;
        q.pop();
        count++;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m || maze[xx][yy] == '#' || v[xx][yy]) {
                continue;
            }
            v[xx][yy] = true;
            if (maze[xx][yy] == 'F') {
                kfc.push_back(point(xx, yy, count));
            } 
            q.push(point(xx, yy, count));
        }        
    }
    if (kfc.size() == 0) {
        cout << "Meeting cancelled";
        return 0;
    }
    // bfs from my friends home
    fill(v.begin(), v.end(), vector<bool>(m, false));
    v[fx][fy] = true;
    q.push(point(fx, fy, 0));
    while (!q.empty()) {
        point p = q.front();
        int x = p.x;
        int y = p.y;
        int count = p.mc;
        q.pop();
        count++;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m || maze[xx][yy] == '#' || v[xx][yy]) {
                continue;
            }
            v[xx][yy] = true;
            if (maze[xx][yy] == 'F') {
                // cout << "checking (" << xx << "," << yy << ") current count " << count << '\n';
                for (auto it : kfc) {
                    // cout << " KFC (x,y) = (" << it.x << "," << it.y << ") how far? " << it.mc <<"\n";                    
                    if (it.x == xx && it.y == yy) {
                        if (answer == 0) {
                            answer = count + it.mc;
                        } else {
                            answer = min(answer, count + it.mc);
                        }
                    }
                }
            } 
            q.push(point(xx, yy, count));
        }                
    }
    if (answer == 0) {
        cout << "****Meeting cancelled";
    } else {
        cout << answer;
    }
    return 0;
}