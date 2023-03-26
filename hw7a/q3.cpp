// C. Game of WOW (World of Warcraft)
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6570&fragments=11885&problemId=1376&pattern=0
// Same problem found in hw10 q2.cpp (BFS implementation)
/*
Small A is a small warlock in WoW - World of Warcraft. As a warlock, it is quite shameful not being able to solo a BOSS. 
The so-called solo BOSS is to single-handed defeat the BOSS, so how can Small A with great sense of honor not to do it? 
Now Small A needs to go to the end of the Doom to find the BOSS. Small A looked at the map of Doom that is an N*M 
rectangular maze (N, M<=100) with minions and portals, where 1 means minion blocking the way, 0 means pass, and uppercase 
letters indicate teleport portals. How do the teleport portals work? When you enters the portal A, you'll be immediately 
teleported to another A, and the same for the other letters. The data ensures that each portal has one and only one 
corresponding portal.

The entrance is at the upper left (1,1), but the BOSS is hiding at the bottom right (N,M). small A is very eager to 
complete the solo mission and then he can go to other warriors to show off, so Small A would never waste time on the 
minions by avoiding them, and want to reach BOSS as soon as possible through the portals. How to find the fastest way? 
Of course, programming!

Input:
The first line of 2 data: n m;
The following n lines, m chars per line representing the map of Doom. There are no spaces between the map data. You can 
only go one step at a time, at the direction up, down,left or right. The upper left corner is the entry point and the 
lower right corner is the exit point where the BOSS is located.

Output:
An integer that tells the least steps it takes for Small A find the BOSS. If the small A cannot reach the target, then 
output "No Solution.".

Sample input 1:
3 4
0000
00A0
A000

Sample output 1:
4

Sample input 2:
4 6
010100
01A100
011101
0000A0

Sample output 2:
10

Sample input 3:
4 4
0ADB
CBAE
FFCD
GGE0

Sample output 3:
3

Sample input 4:
4 4
0000
0AB0
0BA1
0010

Sample output 4:
No Solution.

Data range:
For 60% of the data, n, m <= 20
For 100% of the data, n, m <= 100

Hint:
The route for the example input 1 is as follows:
(1, 1) - (2, 1) - (3 ,1)(2, 3) - (2, 4) - (3, 4)
The route for the example input 2 is: 
(1，1）-（2，1）-（3，1）-（4，1）-（4，2）-（4，3）-（4，4）-（4，5）（2，3）-（1，3）-（2，3）（4，5）-（4，6）
*/
#include <iostream>
#include <vector>
using namespace std;

vector<string> maze;
vector<vector<bool>> visited;
vector<vector<int>> portals(26, vector<int>(4, -1));
int n,m;
int answer=-1;
int counter=0;

void path(int x, int y){
  
  if (answer > 0 && counter >= answer) return;

  if(x==n-1 && y==m-1){
    if(answer==-1){
      answer=counter;
    }
    else{
      answer=min(answer, counter);
    }
    return;
  }
  
  if (x>=0 && x<n && y>=0 && y<m){
    if(maze[x][y]>='A'){
        int nx, ny;
        if(x==portals[maze[x][y]-'A'][0] && y==portals[maze[x][y]-'A'][1]){
            nx=portals[maze[x][y]-'A'][2];
            ny=portals[maze[x][y]-'A'][3];
        }
        else{
            nx=portals[maze[x][y]-'A'][0];         
            ny=portals[maze[x][y]-'A'][1];       
        }
        x = nx;
        y = ny;
    }
 
    if (maze[x][y] != '1' && visited[x][y]==false){
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
  cin >> n >> m;

  for(int i=0; i<n; i++){
    string s;
    vector<bool> vis(m, false);
    cin >> s;
    maze.push_back(s);
    visited.push_back(vis);
    for(int j=0; j<m; j++){
        if(s[j]>='A' && s[j]<='Z'){
            if(portals[s[j]-'A'][0]==-1){
                portals[s[j]-'A'][0]=i;
                portals[s[j]-'A'][1]=j;
            }
            else{
                portals[s[j]-'A'][2]=i;
                portals[s[j]-'A'][3]=j;
            }
        }
    }
  }

    // for(int i=0; i<26; i++){
    //     for(int j=0; j<4; j++){
    //         cout << portals[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for(int i=0; i<n; i++){
    //     cout << maze[i] << endl;
    // }

    // cout << px1 << py1 << px2 << py2 << endl;

  path(0,0);

  if(answer==-1){
    cout << "No Solution." << endl;
  }
  else{
    cout << answer << endl;
  }
}