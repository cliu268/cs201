// A. Check the Maze
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6395&fragments=11613&problemId=9190&pattern=0
/*
Given a n x n matrix, a start and end position, find if there exists a path from the start to the finish. 
The maze is a binary (0 and 1) matrix where 0 means open cell and 1 means a wall. 
You can move up, down, left or right from each position. 

Input 
first line has 4 integers, n (the dimensions of the matrix) 1 ≤ n ≤ 10, start_x, start_y, end_x, end_y
The next n lines represent the maze

Output
YES if you can reach the end point or NO if you cannot. 

Sample Input
3 0 0 2 2
0 0 0
0 1 0
0 0 0

Sample Output
YES
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map;
vector<vector<bool>> visited;
int n, x1, y1, x2, y2;
bool found=false;

void path(int x, int y){
  
  if(x==x2 && y==y2){
    found=true;
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
  cin >> n >> x1 >> y1 >> x2 >> y2;

  for(int i=0; i<n; i++){
    vector<int> rows(n);
    vector<bool> vis(n, false);
    for(int j=0; j<n; j++){
      cin >> rows[j];
    }
    map.push_back(rows);
    visited.push_back(vis);
  }

  path(x1, y1);

  if(found==false){
    cout << "NO" << endl;
  }
  else{
    cout << "YES" << endl;
  }
}