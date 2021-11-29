// Q1 Super Shelf 2
/*
Time limit：1   Memory limit：32M 

Description：
Farmer John recently bought a book shelf. It was filled with books with only the top available. 
Now there are N (1 <= N <= 20) cows with height H_i (1 <= H_i <= 1,000,000). Suppose the sum of their height is S and 
the height of the shelf is B (1 <= B <= S). The cows have to stand on each other to reach the top of the book shelf. 
The height of the cow tower is the sum of their height. The higher the tower, the less stable it will be. So the cows 
want to find a solution such that when the height of the tower is no less than the shelf's height, the tower height can 
be as small as possible. Please design a program to find out at least how much higher the cow tower should be than the shelf.

Input：
The first line contains two integers N and B (separated by space)
The second to the N+1 line: the i+1 line contains an integer H_i

Output：
The first line contains a non-negative integer, which is the smallest difference between the height of the milk tower 
and the shelf.

Sample input 1：
5 16
3
1
3
5
6

Sample output 1：
1

Note：
1<=n<=20
1<=H_i<=1000000
*/
// same question as hw5 q1, refer to https://github.com/cliu268/cs201/blob/main/hw5/q1.cpp
// following using BFS to solve it
#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

ll b;
vector<ll> cows;
queue<vector<ll>> q;
ll least=999999999999999999;

bool shareIndicies(vector<ll> indicies, int compare) {
    for (int i=0; i<indicies.size(); i++) {
        if (compare==indicies[i]) {
            return true;
        }
    }
    return false;
}

ll sum(vector<ll> vect) {
  ll ans=0;
  for (int i=0; i<vect.size(); i++) {
    ans+=cows[vect[i]];
  }
  return ans;
}

void exploreNeighbors(vector<ll> current) {
  if (sum(current)>=b) {
    if (least>sum(current)-b) {
      least=sum(current)-b;
    }
    return;
  }
  for (int i=0; i<cows.size(); i++) {
    if (shareIndicies(current, i)==false) {
      vector<ll> temp=current;
      temp.push_back(i);
      q.push(temp);
    }
  }
}

void bfs(ll initial) {
  q.push({initial});
  while (!q.empty()) {
    vector<ll> current=q.front();
    q.pop();
    exploreNeighbors(current);
  }
}

int main() {
  int n;
  cin>>n>>b;
  for (int i=0; i<n; i++) {
    ll x;
    cin>>x;
    cows.push_back(x);
  }
  for (int i=0; i<n; i++) {
    bfs(i);
  }
  cout<<least;
} 