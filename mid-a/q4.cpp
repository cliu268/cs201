// D. Wandering Cow
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6566&fragments=11647&problemId=8020&pattern=0
// Same question found in hw8 q2.cpp where dynamic programming is used and won't TLE
// Implementation here uses pure DFS and runs TLE
/*
Time limit: 1 Memory Limit：32M

Description:
Cows walk around on a grassland partioned into N rows and M coloumns (2 <= N <= 100; 2 <= M <= 100), trying to find the place with 
best grass.  Farmer John at a certain time saw Bessie (name of a cow) at spot (R1, C1). After T seconds (0 < T <= 15) John meets 
Bessie at (R2,C2) again. John is not sure if Bessie has been (R2, C2) druing that T seconds already. He is only sure that Bessie is 
now at (R2, C2). Let's assume S as the total possible paths between (R1, C1) and (R2, C2) in the past T seconds. John wishes to 
compute the value of S.

The cow moves 1 unit (distance) every second, either in horizontal or vertical direction and will never stay in the same place 
without moving. Of course the cow can neighter go to the spots where there are trees, nor she moves out of the grassland.

Now you have a map of the grassland, in which '.' means normal spots (flat area) and '*' indicates where trees are. Please find out 
all possible paths from (R1, C1) to (R2, C2) a cow could take in T seconds.

Input:
1st line has 3 numbers seperated by spaces: N, M, T.
2nd to N+1st lines: i+1st line has M characters ('.' or '*'). These characrters descriobe the conditions ("normal" or "has tree") 
of each spot on row i. 
N+2nd line has 4 numbers seperated by spaces: R1, C1, R2, C2

Output
One line contain the value of S (as descibed in the "description" part above).

Sample input 1：
4 5 6
...*.
...*.
.....
.....
1 3 1 5

Sample output 1：
1

Note：
2 ≤ n,m ≤ 100
0 < T ≤ 15
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map;
int n, m, t, xx, yy, x2, y2;
int answer=0;
int counter=0;

void path(int x, int y){
  if(x==x2-1 && y==y2-1 && counter == t){
    answer++;
    return;
  }
        
  if (x>=0 && x<n && y>=0 && y<m){
    if (map[x][y] != 1 && counter -1 < t){
      counter ++;

      //cout << "[" << x << "][" << y << "] : " << counter << ", ";
      
      path(x-1, y);
      path(x+1, y);
      path(x, y-1);
      path(x, y+1);
      counter --;
    }
  } 
  
}

int main() {
  cin >> n >> m >> t;

  for(int i=0; i<n; i++){
    string input;
    cin >> input;
    vector<int> row(m);
    for(int j=0; j<m; j++){
      if(input[j]=='.'){
        row[j] = 0;
      }
      else if(input[j]=='*'){
        row[j] = 1;
      }
    }
    map.push_back(row);
  }

  cin >> xx >> yy >> x2 >> y2;

  path(xx - 1, yy - 1);

  cout << answer << endl;
}

// Answer given by xcamp
/*
#include<iostream>
#include<vector>
using namespace std;

int n = 0;
int m = 0;
int t = 0;
int r1 = 0;
int c1 = 0;
int r2 = 0;
int c2 = 0;
int counter = 0;
vector<vector<char>> matrix;

// Valid function
bool is_valid(int row, int col, int time) {
  if (time > t || row<0 || col<0 || row>=n || col>=m || matrix[row][col]=='*') {
    return false;
  }  
  return true;
}

void wandering_cow(int row, int col, int time) {
  // if (time>t) return;
  if (!is_valid(row, col, time)) {
    return;
  }
  if (abs(r2-1-row) + abs(c2-1-col) > (t-time)) {
    return;
  }
  if (time == t) {
    if (row==r2-1 && col==c2-1) {
      counter++;
    }
    return;
  }

  int dr[4] = {-1, 1, 0, 0};
  int dc[4] = {0, 0, -1, 1};

  for (int i=0; i<4; i++) {
    wandering_cow(row+dr[i], col+dc[i], time+1);
  }
}

int main() {
  cin >> n >> m >>t;

 matrix = vector<vector<char>>(n, vector<char>(m));
 
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> matrix[i][j];
    }
  }

  cin >> r1 >> c1 >> r2 >> c2;
  wandering_cow(r1-1, c1-1, 0);
  cout << counter;
}
*/