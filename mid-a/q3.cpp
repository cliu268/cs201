// C. Treasure Matrix
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6566&fragments=11647&problemId=9862&pattern=0
// Same question found in mid q5.cpp
/*
Time limit：1s   Memory limit: 128M
Description：
Explorers in the country of X recently discovered some ruins. It is like a matrix but it has a lot of treasures.
Explorers figured out the map of this matrix using an "Eagle's Eye" detector. This is a 2D map, where a '#' means a trap which they cannot get through 
no matter what they do. An '*' means an accesible spot. Some spots have treasures, whose value is indicated by a number. 
The unique thing about this matrix is that once you move on from a spot, that spot will disappear. You will never be able to go to the same spot again.
The explorers want to know the maximum amount of treasures they can get if they enter from the upper left entrance and exit from the bottom right exit.

Input：
1st line has two integers n and m to describe the matrix size.
Then there will be n lines, each of which has m characters. These lines/row describe the map. 
It is guaranteed that there is no trap at the extrance. 

Output：
One integer number, which is the max value the explorer can obtain. 
if you cannot get to the exit, output -1.

Sample Input：
5 6 
1****# 
*###2# 
4###*# 
*###1# 
**1***

Sample Output ：
6

Constraints：
1 <= N，M <= 7，0 <= each treasure <= 9
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map;
vector<vector<bool>> visited;
int n, m;
int answer=-1;
int counter=0;

void path(int x, int y){
  
  if(x==n-1 && y==m-1){
    if(map[x][y]>0){
      counter += map[x][y];
    }
    if(counter!=0){
      answer = max(answer, counter);
    }
    if(map[x][y]>0){
      counter -= map[x][y];
    }
    return;
  }
  
  if (x>=0 && x<n && y>=0 && y<m){
    if (map[x][y] != -1 && visited[x][y]==false){
      visited[x][y]=true;
      if(map[x][y]>0){
        counter += map[x][y];
      }
      path(x-1, y);
      path(x+1, y);
      path(x, y-1);
      path(x, y+1);
      visited[x][y]=false;
      if(map[x][y]>0){
        counter -= map[x][y];
      }
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
      else if(input[j]=='#'){
        row[j] = -1;
      }
      else{
        row[j] = input[j]-48; // 48 is the ascii code for '0'
      }
    }
    vector<bool> vis(m, false);
    map.push_back(row);
    visited.push_back(vis);
  }

  path(0,0);

  cout << answer << endl;
}