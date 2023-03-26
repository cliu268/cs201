// A. Assign jobs
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6571&fragments=11886&problemId=7998&pattern=0
/*
Description
     Suppose there are n tasks and n people。If you give task i to the person j, you have to pay Cij. Please design a program, which gives each 
     person a different task, and takes the minimum cost. 

Input
     The first line contains 1 positive integer n(1≤n≤20)。  
     The next n lines，each contains n numbers，which means the pay for the tasks.

Output
     An integer, which is the minimum cost.

Sample input
3
10 2 3
2 3 4
3 4 5

Sample output
9
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tasks;
vector<int> visited;
int n;
int answer=0, temp=0;

void cost(int x){
    if(x==n){
        if(answer!=0){
            answer = min(answer, temp);
        }
        if(answer==0){
            answer=temp;
        }
    }
    else{
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                temp += tasks[x][i];
                if(answer !=0 && temp>answer){
                    temp -= tasks[x][i];
                    continue;
                }
                visited[i]=1;
                cost(x+1);
                temp-=tasks[x][i];
                visited[i]=0;
            }
        }
    }
}

int main(){
    
    cin >> n;

    for(int i=0; i<n; i++){
        vector<int> rows(n);
        for(int j=0; j<n; j++){
            cin >> rows[j];
        }
        tasks.push_back(rows);
        visited.push_back(0);
    }

    cost(0);
    cout << answer << endl;
}