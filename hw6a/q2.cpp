// B. Cow Hopscotch (Bronze)
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6568&fragments=11884&problemId=15189&pattern=0
/*
Just like humans enjoy playing the game of Hopscotch, Farmer John's cows have invented a variant of the game for themselves to play. Being played by 
clumsy animals weighing nearly a ton, Cow Hopscotch almost always ends in disaster, but this has surprisingly not deterred the cows from attempting to 
play nearly every afternoon.

The game is played on an R by C grid (2 <= R <= 15, 2 <= C <= 15), where each square is colored either red or blue. Cows start in the top-left square 
and move to the bottom-right square by a sequence of jumps, where a jump is valid if and only if

You are jumping to a square of a different color,
The square that you are jumping to is at least one row below the current square that you are on, and
The square that you are jumping to is at least one column to the right of the current square that you are on.
Please help the cows compute the number of different possible sequences of valid jumps that will take them from the top-left square to the 
bottom-right square.

INPUT FORMAT: (file hopscotch.in)
The first line contains the two integers R and C. The next R lines will each contain C characters. Each character is either 'R' or a 'B', indicating 
a red square or a blue square.

OUTPUT FORMAT: (file hopscotch.out)
Output the number of different ways one can jump from the top-left square to the bottom-right square.

SAMPLE INPUT:
4 4
RRRR
RRBR
RBBR
RRRR

SAMPLE OUTPUT:
3
[Problem credits: Nick Wu, 2015]
*/
#include <iostream>
#include <vector>
using namespace std;
int n,m;
int answer=0;
vector<string> map;

void hopscotch(int x, int y){
  if(x == n-1 && y == m-1){
    answer ++;
    return;
  }
  for(int i=x+1; i<n; i++){
    for(int j=y+1; j<m; j++){
      if(map[x][y] != map[i][j]){
        hopscotch(i, j);
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i=0; i<n; i++){
    string line;
    cin >> line;
    map.push_back(line);
  }

  hopscotch(0,0);

  cout << answer << endl;
}