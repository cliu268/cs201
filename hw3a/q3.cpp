// C. Beautiful Permutations
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6393&fragments=11612&problemId=9193&pattern=0
/*
A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, your task is to count the number of beautiful permutations.

Input
The only input line contains an integer n.

Output
Print the number of beautiful permutations 

Sample Input
5

Sample Output
14

Hint: an example beautiful permutation is 13524
*/
#include <iostream>
#include <vector>
using namespace std;

int n;
int sum=0;
vector<bool> vis(10, false);
vector<int> a(10);

void perm(int m){
  if(m==n){

    int i=0;
    
    for(i=0; i<n-1; i++){
      if(abs(a[i]-a[i+1]) == 1 ){
        break;
      }      
    }
    
    if(i==n-1){
      sum++;
    }
    
  }
  else{
    for(int i=1; i<=n; i++){
      if(vis[i]){
        continue;
      }
      vis[i] = true;
      a[m] = i;
      perm(m+1);
      vis[i] = false;
    }
    
  }
  
}

int main()
{
  cin >> n;
  perm(0);
  cout << sum << endl;
}