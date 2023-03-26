// A. Flood
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6573&fragments=11889&problemId=9659&pattern=0
/*
Farmer John has a NxN square field. The field is divided into 1x1 grids. Some grids in the field remain at ground level, while others 
fall below. There is a faucet to water the field located at some position inside the grid. One day Farmer John forgot to turn off the 
faucet. How many grids are going to be flooded? Assume only the grids lower than ground can be filled with water. Water can only flow to 
4 directions, up, down, left and right. Note that water will flood the sqare where the faucet is located. 

Input:
First line: one number N represents the size of the field (N <= 200)
The following N lines represents the NxN grids. '-' is the ground level grid and '_' is the lower-than-ground-level grids.
* is where the faucet is.
Faucet grid will be flooded too.

Output:
One number represents how many grids will be flooded.

Sample input:
4
-_-*
---_
_---
_---

Sample output:
2
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> maze;
int a=0;
int n;
int x,y;

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
  floodfill(x, y-1);
  floodfill(x, y+1);
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++){
    string input;
    cin >> input;
    vector<int> row(n);
    for(int j=0; j<n; j++){
      if(input[j]=='-'){
        row[j]=1;
      }
      else if(input[j]=='_'){
        row[j]=0;
      }
      else{
        x=i;
        y=j;
        row[j]=0;
      }
    }
    maze.push_back(row);
  }
  
  floodfill(x, y);

  cout << a << endl;
}