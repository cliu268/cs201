// B. Red and black
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6392&fragments=11611&problemId=8120&pattern=0
/*
Time limit：1ms   Memory limit：512M
Description：
A rectangular room is covered by square tiles which is either red or black. A man stands on a black tile, and he can move to one 
of the adjacent four tiles. The rule is he can only move to the black tiles, but not the red ones.

Write a program to calculate the number of black tiles he can reach.

Input：
First line is two positive integers W and H. W and H are the numbers of tiles on x and y directions. 
The sum of W and H can not exceed 20.
Next H lines is W characters per line. Each character represents the color of the tile. 
'.' - black tile
'＃' - red tile
'@' - man on the black tile (appear only once in the data set)
When W and H equal to 0 , it means the end of input.

Output：
The number of black tiles he can reach (including the original one).

Sample input：
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..

Sample output：
13
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> maze;
int a=0;
int w;
int h;

void floodfill(int x, int y){
  
  if (x<0 || x>=h || y<0 || y>=w){
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
  int x;
  int y;  

  cin >> w >> h;
  
  for(int i=0; i<h; i++){
    string input;
    cin >> input;
    vector<int> row(w);
    for(int j=0; j<w; j++){
      if(input[j]=='.'){
        row[j] = 0;
      }
      else if(input[j]=='#'){
        row[j] = 1;
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