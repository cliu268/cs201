// A. The Sea of Trash
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6568&fragments=11884&problemId=8010&pattern=0
/*
Description：
You will become sad if you fall into the sea of trash. But Boy Ma is planning not to.
Boy Ma gives you a map of the Sea of Trash. It has n rows (from 1 to n) and m columns (from 1 to n). Two spots are connected if they are neighbors. 
An example: (x,y) is connected to (x,y), (x-1,y), (x+1,y), (x,y-1) and (x,y+1) only. 

Every spot could have trash in it (the spot has a value of 1) or not (value=0). 
Let's define the so-called Trash Block. A Trash Block is an area where any two spots of trash are connected as neighbors.

Now find out how many spots the biggest trash block has.
You may need to refer to the samples for better understanding of the questions.

Input：
The first line has two numbers n and m.
Then there are n lines, each line has m numbers. Those numbers are either 1 or zero.

Output：
One number.

Sample Input：
5 4
0101
0111
1000
1100
0101

Sample Output：
5

Constraints：
1 <= n, m <= 50
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int answer, counter=0;
vector<vector<int>> map;
vector<vector<bool>> visited;

void trash(int x, int y){

  if (x>=0 && x<n && y>=0 && y<m){
    if (map[x][y] == 1 && visited[x][y]==false){
      visited[x][y]=true;
      counter++;
      trash(x-1, y);
      trash(x+1, y);
      trash(x, y-1);
      trash(x, y+1);
    }
  }
  
}

int main() {
  cin >> n >> m;
  
  for(int i=0; i<n; i++){
    vector<int> line(m);
    string row;
    cin >> row;
    vector<bool> vis(m, false);
    for(int j=0; j<m; j++){
      if(row[j] == '0'){
        line[j] = 0;
      }
      else{
        line[j] = 1;
      }
    }
    map.push_back(line);
    visited.push_back(vis);
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(map[i][j] == 1 && visited[i][j] == false){
        trash(i, j);
        answer = max(answer, counter);
        counter=0;
      }
    }
  }

  cout << answer << endl;
  
}