// B. Pouring Milk
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6569&fragments=11887&problemId=8017&pattern=0
// Same question as in final q5.cpp
/*
Description：
Farmer John has three buckets of A, B, C liters. A,B,C are integers from 1 to 20. Buckets A and B are empty initially, while C is filled with milk. 
Sometimes, the farmer pours the milk from one bucket to another until one bucket becomes empty or one bucket is full. Assume there is no loss of milk 
in the process. Please write a program to help the farmer find all possible amount of milk left in bucket C while bucket A is empty.

Input：
A single line which contains three integers A, B and C.

Output：
A single line which contains all the possibilities of the amount (in ascending order) of milk in bucket C when bucket A is empty .

Sample input 1：
8 9 10

Sample output 1：
1 2 8 9 10

Note：
1<=A, B, C<=20
*/
#include <iostream>
#include <vector>
using namespace std;
int a, b, c;
vector<vector<vector<bool>>> state(21, vector<vector<bool>>(21, vector<bool>(21, 0)));

void pour(int aa, int bb, int cc){
    if(state[aa][bb][cc]==1){
        return;
    }
    else{
        int x = 0;
        state[aa][bb][cc]=1;
        x = min(aa, b-bb); // a to b
        pour(aa-x, bb+x, cc);
        x = min(aa, c-cc); // a to c
        pour(aa-x, bb, cc+x);
        x = min(bb, a-aa); // b to a
        pour(aa+x, bb-x, cc);
        x = min(bb, c-cc); // b to c
        pour(aa, bb-x, cc+x);
        x = min(cc, a-aa); // c to a
        pour(aa+x, bb, cc-x);
        x = min(cc, b-bb); // c to b
        pour(aa, bb+x, cc-x); 
    }
}

int main(){
    cin >> a >> b >> c;

    pour(0, 0, c);

    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++){
            if(state[0][j][i]==1){
                cout << i << " ";
            }
        }
    }
}