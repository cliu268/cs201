// Codeforces Round 856 (Div. 2)
// https://codeforces.com/contest/1794/problem/C
// #include <iostream>
// #include <vector>
// using namespace std;
 
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     int t; cin>>t;
//     while (t--) {
//         int n; cin>>n;
//         vector<int> vect(n);
//         int ans=1; int start=0;
//         for (int i=0; i<n; i++) {
//             cin>>vect[i];
//             int count=0;
//             for (int j=0; j<=i; j++) {
//                 count=j;
//                 if (vect[j]>=(i-j+1)) {
//                     break;
//                 }
//             }
//             cout<<(i+1-count)<<" ";
//         }
//         cout<<"\n";
//     }
// }

#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> vect(n);
        int ans=1; int start=0;
        for (int i=0; i<n; i++) {
            cin>>vect[i];
            if (i==0) {
                cout<<1<<" ";
                continue;
            }
            int comp=(i+1-start);
            while (vect[start]<comp && start<i) {
                start++;
                comp--;
            }
            cout<<(i-start+1)<<" ";
        }
        cout<<"\n";
    }
}
