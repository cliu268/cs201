// Q1 Bessie's secret grassland
/*
Time limit：1   Memory limit：32M
Description：
Farmmer John put hay on the ground. The hay is in the form of square with non-negative side length (can be 0). One day, 
a milk cow Bessie found those hay and wanted to plant them in his secret grassland. He divided the hay into squares of 1*1, 
in order to put them into cells.
Bessie wondered how many ways she can have if she always divide her N amount of hay into 4 pieces. If N=4, then she can 
have 5 different ways of distribution: (1,1,1,1),(2,0,0,0),(0,2,0,0),(0,0,2,0),(0,0,0,2). Inside the bracket are the side 
lengths. Note that (1,2,3,4) and (4,3,2,1) are different.

Input：
a single line which contains an integer N

Output：
a single line which contains an integer, which is the number of ways Bessie can have.

Sample input 1：
4

Sample output 1：
5

Note：
1<=n<=10000
*/
#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
    int n, ans=0;
    cin >> n;
    for (int i = 0; i*i <= n; i++) {
        if (i*i == n) {
            ans++;
            break;
        }
        for (int j = 0; i*i + j*j <= n; j++) {
            if (i*i + j*j == n) {
                ans++;
                break;
            }
            for (int k = 0; i*i + j*j + k*k <= n; k++) {
                if (i*i + j*j + k*k == n) {
                    ans++;
                    break;
                }
                for (int l = 0; i*i + j*j + k*k + l*l <= n; l++) {
                    if (i*i + j*j + k*k + l*l == n) {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
}

// Some answer from online - iteration way
// #include<cstdio>
// int n;
// int f[10010][5];
// int main()
// {
// 	scanf("%d",&n);
// 	f[0][0]=1;
// 	for(int i=1;i<=n;i++)
// 	  for (int j=1;j<=4;j++)
// 	    for (int k=0;k*k<=i;k++)
// 	      f[i][j]+=f[i-k*k][j-1];
// 	printf("%d",f[n][1]+f[n][2]+f[n][3]+f[n][4]);
// }

// Some answer from online - dfs way
// #include<bits/stdc++.h>
// using namespace std;    
// int n,num;
// void cao(int k,int s){
//     if(k==4) {
//         if(s==n) {
//             num++;
//         }
//         return;
//     }
//     for(int i=0;i<=sqrt(n);i++) {
//         cao(k+1,s+i*i);
//     }
// }
// int main()
// {
//     cin>>n;
//     cao(0,0);
//     cout<<num;
//     return 0;
// }
