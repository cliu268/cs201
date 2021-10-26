// Q2 Using recursion to find the value of n！
/*
Time limit：0.2   Memory limit：32M

Description：
Please use recursion to find the value of 1*2*3*...*n
modulo 998244353

Input：
a positive integer representing n

Output：
output the answer

Sample input 1：
1

Sample output 1：
1

Note：
1<=n<=10000
*/
// A[n] = A[n-1] * n
#include <iostream>
using namespace std;

long long solve(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return solve(n-1) * n % 998244353;
    }
}

int main(void) {
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}