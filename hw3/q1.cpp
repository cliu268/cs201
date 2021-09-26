// Q1 Maoge's Tower
/*
【Description】
maoge has N bricks (2<=N<=1000)，and he wants to build a tower. If he put brick A over brick B, then the 
length of A should be smaller than that of B, which is D（1<=D<=n）. Please find out how many ways there are. 
Print the answer and mod 1000000007.

Note that the height of the tower can't be 0.

【Input】
The first line: N，D
The second line: N positive integers，representing the length of each brick (N<=10000)

【Output】
Number of solutions. mod 1000000007

【Sample input】
4 1
1 2 3 100
【Sample output】
15
*/
#include <iostream>
#include <vector>
using namespace std;

int mTower(vector<int> bricks, int D) {
    vector<int> ans(bricks.size() + 1);
    ans[0] = 0; // invalid case
    ans[1] = 1;
    for (int i = 1; i < bricks.size(); i++) {
        //cout << bricks[i] << " ";
        int j;
        for (j=i; j>0; j--) {
            if (bricks[i] - bricks[j-1] >= D) break; // j is the brick that satisifies condition D
        }
        ans[i+1] = 1 + ans[i] + ans[j]; 
    }
    return ans[bricks.size()];
}

int main(void) {
    int n, D;
    cin >> n >> D;
    vector<int> bricks(n);
    for (int i = 0; i < n; i++) {
        cin >> bricks[i];
    }
    cout << mTower(bricks, D) << endl;
}