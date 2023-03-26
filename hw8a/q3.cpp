// C. Super shelf 2
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6571&fragments=11886&problemId=8013&pattern=0
// Same question in hw5 q1.cpp (DFS) and hw10 q1.cpp (BFS)
/*
Description：
Farmer John recently bought a book shelf. It was filled with books in almost no time and now only the top still has some space. So cows need to put books 
there on the top of the shelf.
Now there are N (1 <= N <= 20) cows with height H_i (1 <= H_i <= 1,000,000). Suppose the sum of their height is S and the height of the shelf is 
B (1 <= B <= S). The cows have to stand on each other to reach the top of the book shelf. The height of the cow tower is the sum of their height. 
And this total height has to be higher than the book shelf in order to place items there. The higher the tower, the less stable it will be. So the 
cows want to find a solution such that when the tower is still taller than the shelf, the tower height can be as less as possible. Please design a 
program to find out least height that the cow tower should be in order to reach the shelf top.

Input：
The first line contains two integers N and B separated by a space.
The second to the N+1-th line: the i+1-th line contains an integer H_i for for cow i.

Output：
The first line contains a non-negative integer, which is the smallest difference between the heights of the cow tower and the shelf.

Sample Input：
5 16
3
1
3
5
6

Sample Output：
1 

Constraints：
1<=n<=20
1<=H_i<=1000000
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
ll n,b;
vector<ll> height;
vector<bool> visited;
ll answer=0, temp=0; // temp is the current total height of cow stack

void shelf(){
    if(temp>b){
        if(answer!=0){
            answer= min(answer, temp-b);
        }
        else{
            answer = temp-b;
        }
    }
    else{
        for(ll i=0; i<n; i++){
            if(visited[i]==0){
                temp += height[i];
                visited[i] = true;
                shelf();
                temp -= height[i];
                visited[i] = false;
            }
        }
    }
}

int main(){
    cin >> n >> b;
    for(ll i=0; i<n; i++){
        ll m;
        cin >> m;
        height.push_back(m);
        visited.push_back(false);
    }
    shelf();
    cout << answer << endl;
}