// Q1 Bunny Family II
/*
It takes one months for a baby rabbits to grow into adult rabbits.
Each month a pair of adult rabbits will give birth to three pairs of baby rabbits.
Given one pair of baby rabbits in the month 1, how many pair of adult rabbits and how many pairs of baby rabbits in 
total will there be in Nth (N<=20) month?

Sample input:
2

Sample output:
1
0
*/
// A(n) = A(n-1) + B(n-1)
// B(n) = A(n-1) * 3
// A(1) = 0
// B(1) = 1
#include <iostream>
using namespace std;

int A[20];
int B[20];

int main(void) {
    int n;
    cin >> n;
    A[0] = 0;
    B[0] = 1;
    for (int i = 1; i < n; i++) {
        A[i] = A[i-1] + B[i-1];
        B[i] = A[i-1] * 3;
    }
    cout << A[n-1] << '\n';
    cout << B[n-1] << '\n';
    return 0;
}