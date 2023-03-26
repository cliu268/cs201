// B. Shortest Path
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6395&fragments=11613&problemId=9191&pattern=0
/*
Given a n by n binary matrix (0 means accessible cell and 1 means blocker), please find the shortest path in a maze from a 
starting position to the destination. At each step you can move up, down, left or right. The starting position is the top left 
corner (0, 0) and the ending position is the bottom right corner (n - 1, n - 1). 
Note: If no valid path exisits, print -1. 

Input
First line is n, the size of the matrix 1 ≤ n ≤ 10
Next n lines make up the matrix

Output
A single integer value, the shortest path from the start to the end

Sample Input
3
0 0 0
1 0 1
0 0 0

Sample Output
5
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map;
vector<vector<bool>> visited;
int n;
int answer=-1;
int counter=1;

void path(int x, int y){
  
  if(x==n-1 && y==n-1){
    if(answer==-1){
      answer=counter;
    }
    else{
      answer=min(answer, counter);
    }
    return;
  }
  
  if (x>=0 && x<n && y>=0 && y<n){
    if (map[x][y] != 1 && visited[x][y]==false){
      visited[x][y]=true;
      counter++;
      path(x-1, y);
      path(x+1, y);
      path(x, y-1);
      path(x, y+1);
      visited[x][y]=false;
      counter--;
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