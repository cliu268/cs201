// B. Bessie's secret grassland
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6571&fragments=11886&problemId=8012&pattern=0
// Same question found in hw8 q1.cpp
/*
Description：
Farmmer John put hay on the ground. The hay is in the form of square with non-negative side length (can be 0). One day, a milk cow Bessie found those 
hay and wanted to plant them in his secret grassland. He divided the hay into squares of 1*1, in order to put them into cells.

Bessie wondered how many ways she can have if she always divide her N amount of hay into 4 pieces. If N=4, then she can have 5 different ways of 
distribution: (1,1,1,1),(2,0,0,0),(0,2,0,0),(0,0,2,0),(0,0,0,2). Inside the bracket are the side lengths. Note that (1,2,3,4) and (4,3,2,1) are different.

Input：
a single line which contains an integer N

Output：
a single line which contains an integer, which is the number of ways Bessie can have.

Sample input：
4

Sample output：
5

Constraints：
1<=n<=10000
*/
#include <iostream>
#include <math.h>
using namespace std;

int n;
int answer=0;

void grass(int x){
    if(x==4){
        if(n==0){
            answer++;
        }
    }
    else{
        for(int i=0; i*i <= n; i++){
            n -= i*i;
            grass(x+1);
            n += i*i;
        }
    }
}

int main(){
    cin >> n;
    grass(0);
    cout << answer << endl;
}