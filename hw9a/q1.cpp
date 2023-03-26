// A. Count 0/1 Numbers
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6569&fragments=11887&problemId=1236&pattern=0
/*
Description
Please calculate how many numbers among 1 to n which are only made of "0" and "1" in decimal numeral system.

Input
An integer n.  （1<=n<=10^9)

Output
An integer.

Sample Input
10

​Sample Output
2 

Notes:
1<=n<=10^9
*/
#include <iostream>
using namespace std;
int n; 
int answer=0;

void count(int curr){
    if(curr>n){
        return;
    }
    else{
        answer ++;
        count(curr*10);
        count(curr*10 + 1);
    }
}

int main(){
    cin >> n;

    count(1);
    cout << answer << endl;
}