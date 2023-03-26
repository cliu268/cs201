// B. K-th Permutation
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6393&fragments=11612&problemId=1016&pattern=0
/*
Given 2 integers N, K, output the K-th permutation of N numbers. 

Input:
Two integers N, K

Output:
One line, the k-th permutation of N numbers

Sample Input
5 3

Sample Output
1 2 4 3 5

Data Range: N <= 10
It is guaranteed that K-th permutation exists. 
*/
#include <iostream>
#include <vector>
using namespace std;

int n,k;
int order=0;
vector<bool> vis(10, false);
vector<int> a(10);

void perm(int m){
  if(m==n){
    order++;
    if(order==k){

      for(int i=0; i<n; i++){
        cout << a[i] << " ";
      }

      cout << endl;
      
      return;
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
  cin >> n >> k;
  perm(0);
}