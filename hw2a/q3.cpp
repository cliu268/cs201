// C. Maze Visit Order
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6392&fragments=11611&problemId=9189&pattern=0
/*
Given a n x m maze, find the visit order of the cells where at each step you try and move in the given order - up, left, right, down. 
The maze is made of 0s and 1s where 1 represents a wall and 0 represents a valid cell we can enter. Our starting position is at 
the top left corner (0, 0).  1 ≤ n, m ≤ 100

Input: 
The first line is two space separated integers n and m, where n is the number of rows and m in the number of columns in the maze. 
The next n lines have m space separated integers, either 0 or 1 representing a wall or open cell. 

Output: 
A n x m matrix where each cell represents the order the cell was visited. If the cell was not able to be visited, place 0. 

Sample Input
3 4
0 0 0 0
1 0 1 0
0 0 0 0
 

Sample Output
1 2 3 4 
0 9 0 5 
10 8 7 6 
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> maze;
vector<vector<int>> answer;
int a=0;
int n,m;

void floodfill(int x, int y){
  
  if (x<0 || x>=n || y<0 || y>=m){
    return;
  }
  
  if (maze[x][y] == 1 || maze[x][y] == -1){
    return;
  }

  a++;
  answer[x][y]=a;
  
  maze[x][y] = -1;

  floodfill(x-1, y);
  floodfill(x, y-1);
  floodfill(x, y+1);  
  floodfill(x+1, y);
}

int main() {
  cin >> n >> m;
  for(int i=0; i<n; i++){
    vector<int> row(m);
    vector<int> zero(m,0);
    for(int j=0; j<m; j++){
      cin >> row[j];
    }
    maze.push_back(row);
    answer.push_back(zero);
  }
  floodfill(0,0);

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << answer[i][j] << " ";
    }
    cout << endl;
  }
}