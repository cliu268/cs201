/*
【Description】
There are n stairs. For each time, maoge can take k steps at most. Please find out how many ways there are for him to reach the n-th step.

【Input】
Two numbers, n and k（n<=100000,k<=100）。

【Output】
a single number, which is the number of ways. modulo 1000000007

【Sample input】
5 2
【Sample output】
8

【Sample input】
30340 77
【Sample output】
327391931
*/
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
long long solution(int n, int k) {
  long long * ans = new long long[n];
  ans[0]=1;
  ans[1]=1;
  for (int i=2; i<n; i++) {
    ans[i]=0;
    for (int j=1; j<=k && j<=i; j++) {
      ans[i]+=ans[i-j];
    }
    ans[i] %= 1000000007;
  }
  return ans[n-1];
}
 
int main(void) {
  int n,k;
  long long ans;
  cin >> n;
  cin >> k;
  printf("%lld", solution(n+1,k));
  return 0;
}
