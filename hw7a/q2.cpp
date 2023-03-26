// B. Roads of Caringness
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6570&fragments=11885&problemId=8019&pattern=0
/*
Description：
John the farmer has N cows (1≤N≤10000) in his farm. He has to patrol the whole farm to make sure all cows are OK.
Each cow's position can be described in a coordinate (X,Y). John always starts from (0,0). Just for fun, he decides to only walk along the directions 
which are parallel to the two axes (east-west, north-south). He changes direction only where he meets a cow. Of course, if necessary, John can keep the 
direction after he meets a cow as well.

If John changes his direction, he will make a turn of 90° (or 270°) or 180°. His goal is to meet all the cows before he returns to (0,0).

Now please find out how many paths satisfy the condition that John examine all the N cows and changes his direction at each cow's place. The same path 
accessed from different directions should be counted twice.

Input：
The first line: an integer N
The second line to the N+1 line: the i+1-th line contains two integers x and y (separated by a space), which are the coordinates of 
the i-th cow（-1000 ≤x, y ≤1000）

Output：
One integer, which is the number of paths that satisfy the condition.
If there is no answer, print 0.

Sample input 1：
4
0 1
2 1
2 0
2 -5

Sample output 1：
2

Note：
1<=N<=12
For the sample case above, the two ways are 1 2 4 3 and 3 4 2 1. Note that at every cow, John makes a turn (90, 180 or 270 degree)
*/
#include <iostream>
#include <vector>
using namespace std;
int n;
int answer=0;
int vis=0;
vector<vector<int>> cows;

bool valid(int x, int y){
    for(int i=0; i<n; i++){
        if(cows[i][2]==1){
            continue;
        }
        else{
            if(cows[i][0]==x || cows[i][1]==y){
                return true;
            }
        }
    }
    return false;
}

void path(int x, int y){
    if(((x==0 && y!=0) || (x!=0 && y==0)) && vis==n){
        answer++;
        return;
    }

    for(int i=0; i<n; i++){
        if(cows[i][2]==1){
            continue;
        }
        else{
            if(cows[i][0]==x || cows[i][1]==y){
                cows[i][2]=1;
                vis++;
                path(cows[i][0], cows[i][1]);
                cows[i][2]=0;
                vis--;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        vector<int> rows(3);
        for(int j=0; j<2; j++){
            cin >> rows[j];
        }
        rows[2]=0;
        cows.push_back(rows);
    }

    path(0,0);

    cout << answer << endl;
}