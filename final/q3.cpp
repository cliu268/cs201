/* Q3 A Strange Game
Time limit：1s   memory limit：512M
description：
A and B are playing chess with a white horse at (x1,y1) and a black horse at (x2,y2). They have to reach (1,1). 
The horse can move in the form of the Chinese character “日”or “田”. Find out the least step for the two 
horses to reach (1,1).

input：
The first line contains two integers x1 and y1
The second line contains two integers x2 and y2

output：
The first line: the distance between the black horse and (1,1)
The second line: the distance between the white horse and (1,1)

sample input 1：
12 16
18 10

sample output 1：
8
9

Note：
x1,y1,x2,y2 <= 20
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> visited(20, vector<bool>(20, false));
struct point {
  int x,y,length;
  point(int a, int b, int c) : x(a), y(b), length(c) {}
};
queue<point> q;
bool broke=false;
int dx[12] = {1, 1, -1, -1, 2, 2, -2, -2, 2, 2, -2, -2};
int dy[12] = {2, -2, 2, -2, 1, -1, 1, -1, -2, 2, -2, 2};

void exploreNeighbors(int x, int y, int length) {
  length++;
  for (int i=0; i<12; i++) {
    int newx=x+dx[i]; int newy=y+dy[i];
    if (newx<0 || newy<0 || newx>=20 || newy>=20) {
      continue;
    }
    if (visited[newx][newy]) {
      continue;
    }
    visited[newx][newy]=true;
    if (newx==0 && newy==0) {
      cout<<length<<"\n";
      broke=true;
      return;
    }
    q.push(point(newx, newy, length));
  }
}
void bfs(int x, int y, int length) {
  q.push(point(x,y,length));
  while (!q.empty() && !broke) {
    point curr=q.front();
    q.pop();
    exploreNeighbors(curr.x, curr.y, curr.length);
  }
  broke=false;
  fill(visited.begin(), visited.end(), vector<bool>(20, false));
  while (!q.empty()) {
      q.pop();
  }
}

int main() {
  int x1, y1, x2, y2;
  cin>>x1>>y1>>x2>>y2;
  bfs(x1-1, y1-1, 0);
  bfs(x2-1, y2-1, 0);
} 