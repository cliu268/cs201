// B. Maze
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6566&fragments=11647&problemId=1226&pattern=0
/*
Description
Given a maze.There are some obstacles cannot be passed in the maze,please calculate the ways you can move from the top left corner to the bottom right.
(One position can not go twice)

Input
The first line contains two integers n,m representing the size of the maze.  1<=n,m<=6

The next n lines,each line contains m characters,representing the maze.
# represents the obstacle
* represents the position which you can go
the top left corner and the bottom right is "*"

Output
An integer.

Sample Input1
5 6
*****#
*###*#
*###*#
*###*#
******

​Sample Output1
2
Sample Input2
6 6
******
******
******
******
******
******

​Sample Output2
1262816
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map;
vector<vector<bool>> visited;
int n, m;
int answer=0;

void path(int x, int y){
  
  if(x==n-1 && y==m-1){
    answer++;
    return;
  }
  
  if (x>=0 && x<n && y>=0 && y<m){
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
  cin >> n >> m;

  for(int i=0; i<n; i++){
    string input;
    cin >> input;
    vector<int> row(m);
    for(int j=0; j<m; j++){
      if(input[j]=='*'){
        row[j] = 0;
      }
      else {
        row[j] = 1;
      }
    }
    vector<bool> vis(m, false);
    map.push_back(row);
    visited.push_back(vis);
  }

  path(0,0);

  cout << answer << endl;
}