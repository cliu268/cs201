// Q1 Run away
/*
Time limit：1s   memory limit：128M

Description：
Ignatius was caught by a devil. One day, the devil is out. This is a great opportunity for Ignatius to run away.
The devil lives in a castle represented by a A*B*C cube (or A B*C matrices). At first, Ignatius is kept in (0,0,0). 
The exit is in (A-1,B-1,C-1). The devil will return to the castle in T minutes, and Ignatius can walk to one of the 
adjacent six coordinates in one minute. Please find out if Ignatius can leave the castle before the devil returns (as 
long as he can reach the exit, he can leave, even if the devil returns at exactly that time). If he can leave, print 
the time he needs. Otherwise, print -1.

Input：
The first line contains a positive integer K, the number of test data.
In each group of test data:
The first line contains four positive integers A,B,C and T(1<=A,B,C<=50,1<=T<=1000), --- the size of the castle and 
the time the devil will return. Then describe the layout of the castle (B lines, C positive integers in each line). 
0 means road, 1 means wall. See sample input.

Output：
If Ignatius can leave, print the minimum time he needs. Otherwise, print -1.

Sample input 1：
1
3 3 4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0

Sample output 1：
11
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<vector<int>>> board;
struct point {
  int x,y,z,counter;
  point(int a, int b, int c, int d) : x(a), y(b), z(c), counter(d) {}
};
queue<point> q;
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int a,b,c,t; 
bool broke=false;
vector<vector<vector<bool>>> visited;
void initialize() {
  for (int i=0; i<a; i++) {
    vector<vector<bool>> x;
    for (int j=0; j<b; j++) {
      vector<bool> row(c,false);
      x.push_back(row);
    }
    visited.push_back(x);
  }
}
void exploreNeighbors(int x, int y, int z, int counter) {
  counter++;
  for (int i=0; i<6; i++) {
    int newx=x+dx[i]; int newy=y+dy[i]; int newz=z+dz[i];
    if (newx<0 || newy<0 || newz<0 || newx>a-1 || newy>b-1 || newz>c-1) {
      continue;
    }
    if (visited[newx][newy][newz]) {
      continue;
    }
    if (board[newx][newy][newz]==1) {
      continue;
    }
    if ((newx==a-1) && (newy==b-1) && (newz==c-1)) {
      cout<<counter;
      broke=true;
      return;
    }
    visited[newx][newy][newz]=true;
    q.push(point(newx,newy,newz, counter));
  }
}
void bfs(point start) {
  q.push(start);
  while (!q.empty() && !broke) {
    point curr=q.front();
    q.pop();
    exploreNeighbors(curr.x, curr.y, curr.z, curr.counter);
  }
  if (broke==false) {
    cout<<-1;
  }
  broke=false;
  initialize();
}
int main() {
  int k; cin>>k;
  while (k--) {
    cin>>a>>b>>c>>t;
    for (int i=0; i<a; i++) {
      vector<vector<int>> temp;
      for (int j=0; j<b; j++) {
        vector<int> row(c);
        for (int k=0; k<c; k++) {
          cin>>row[k];
        }
        temp.push_back(row);
      }
      board.push_back(temp);
    }
    initialize();
    bfs(point(0,0,0,0));
  }
} 