// C. Number of Paths
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6395&fragments=11613&problemId=9192&pattern=0
/*
Given a n x n maze, find the number of ways we can reach the end from the start. The starting position is the top left corner (0, 0) 
and the end position is the bottom right corner (n - 1, n - 1). At each step you can move up, down, left or right. You cannot visit 
the same cell twice during a path. Each cell is either 1 or 0 in value. 1 represents a wall, while 0 represents an empty cell you 
can enter. 

Input
The first line is a single integer n, the size of the grid 1 ≤ n ≤ 10
The next n lines represent the maze

Output
An integer value, the number of paths to the end

Sample Input
2
0 0
1 0

Sample Output
1
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map;
vector<vector<bool>> visited;
int n;
int answer=0;

void path(int x, int y){
  
  if(x==n-1 && y==n-1){
    answer++;
    return;
  }
  
  if (x>=0 && x<n && y>=0 && y<n){
    if (map[x][y] != 1 && visited[x][y]==false){
      visited[x][y]=true;
      path(x-1, y);
      path(x+1, y);
      path(x, y-1);
      path(x, y+1);
      visited[x][y]=false;
    }
  }
  
}

int main() {
  cin >> n;

  for(int i=0; i<n; i++){
    vector<int> rows(n);
    vector<bool> vis(n, false);
    for(int j=0; j<n; j++){
      cin >> rows[j];
    }
    map.push_back(rows);
    visited.push_back(vis);
  }

  path(0,0);

  cout << answer << endl;
}