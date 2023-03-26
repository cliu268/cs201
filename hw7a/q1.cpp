// A. N queens problem
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6570&fragments=11885&problemId=1228&pattern=0
/*
Description:
The "8 queens problem" is a famous problem: You must put 8 queens in a 8x8 chess board, but the queens cannot be in the same row, column, or diagonal. 
There are 92 ways to solve the "8 queens problem".

Now you need to solve the n queen problem, given an n*n board and ask how many pways you can put n queens.

Input:
An integer n. 1<=n<=12

Output:
An integer.

Sample Input:
8

​Sample Output:
92
*/
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int>> maze;
int answer=0;

bool valid(int x, int y){
  for(int j=0; j<n; j++){
    if(maze[x][j]==1){
      return false;
    }
    if(maze[j][y]==1){
      return false;
    }

    if(x+j<n && y+j<n && maze[x+j][y+j]==1) {
      return false;
    }
    if(x+j<n && y-j>=0 && maze[x+j][y-j]==1) {
      return false;
    }
    if(x-j>=0 && y+j<n && maze[x-j][y+j]==1) {
      return false;
    }
    if(x-j>=0 && y-j>=0 && maze[x-j][y-j]==1) {
      return false;
    }
  }
  return true;
}

void queen(int c){
  if(c ==  n){
    answer++;
    return;
  }
  else{
    for(int i=0; i<n; i++){
        if(valid(i, c)){
          maze[i][c]=1;
          queen(c+1);
          maze[i][c]=0;
        }
    }
  }
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++){
    vector<int> rows(n, 0);
    maze.push_back(rows);
  }

  queen(0);

  cout << answer << endl;
}