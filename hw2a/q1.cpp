// A. Floodfill
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6392&fragments=11611&problemId=7421&pattern=0
/*
Description:
Count how many cells can be reached within a N by N maze, with a start point (x, y). You can move up, down, top-left, bottom-right 
for each one step. 

Input:
Three integers in the first line, representing N, and location of start point (x, y).

Next N lines: each line has N 0/1 separated by space, where 0 represents the position you may fill, and 1 represents the barrier.

Output:
Single integer representing number of cells you can reach.

Sample input:
3 0 0
0 0 0
0 1 0
1 0 1

Sample output:
3

Constraints:
1<=N<=500
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> maze;
int a=0;
int n;

void floodfill(int x, int y){
  
  if (x<0 || x>=n || y<0 || y>=n){
    return;
  }
  
  if (maze[x][y] == 1 || maze[x][y] == -1){
    return;
  }

  a++;
  maze[x][y] = -1;

  floodfill(x-1, y);
  floodfill(x+1, y);
  floodfill(x-1, y-1);
  floodfill(x+1, y+1);
}

int main() {
  int x;
  int y;
  cin >> n >> x >> y;
  for(int i=0; i<n; i++){
    vector<int> row(n);
    for(int j=0; j<n; j++){
      cin >> row[j];
    }
    maze.push_back(row);
  }
  floodfill(x, y);

  cout << a << endl;
}