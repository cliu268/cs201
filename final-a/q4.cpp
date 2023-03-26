// D. Number sequence
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6573&fragments=11889&problemId=8018&pattern=0
/*
Given a sequence of digits from 1 to N (3≤N≤9): 123...N, insert "+" for addition, "-" for subtraction, or " " for blank 
(eg "1-2 3" means 1-23) between digits to make the expression evaluates to zero. Please write a program to print out all such expressions.

Input format:
An integer N.

Output format:
In the increasing order of ASCII code (' ' < '+' < '-'), print all expressions that evaluates to zero.

Sample input 1:
7

Sample output 1:
1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7
*/
// https://www.xinyoudui.com/ranklist/student?courseId=350&contestId=4974
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

// xyd answer
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector<int> list;

void dfs(int index, string output, int current, int sum, int sign) {
  //cout << index << "," << output<< ","<< current<<","<<sum <<"," << sign << "."<< endl;
  if(index == n-1){
    output += to_string(list[n-1]);
    sum = sum + (current*10 + list[n-1])*sign;
    //cout << "sum="<< sum <<", "<< output << endl;
    if(sum==0) {
      cout<< output << endl;
    }
    return;
  }
  output += to_string(list[index]);
  int new_current = current*10 + list[index];
  dfs(index+1, output + " ", new_current, sum, sign);
  int new_sum = sum + sign*new_current;
  dfs(index+1, output + "+", 0, new_sum, 1);
  dfs(index+1, output + "-", 0, new_sum, -1);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    list.push_back(i+1);
  }
  dfs(0,"",0,0,1);  
}

*/