/* Q5 Pouring Milk
Time limit 1   Memory limit：32M

Description：
Farmer John has three buckets of size A, B, C. A, B, C are integers from 1 to 20. Originally, bucket A and B 
are empty, while C is filled with milk. Farmer John pours as much milk from one bucket to another as possible. 
Assuming there is no loss of milk in the process, please write a program to help Farmer John find all the 
possible amounts of milk in bucket C when when bucket A is empty.

Input：
Three integers A, B, C.

Output：
All the possible amounts of milk in bucket C when bucket A is empty (in ascending order)

Sample input 1：
8 9 10

Sample output 1：
1 2 8 9 10

Note：
1 ≤ A, B, C ≤ 20
*/
// possible moves : a->b, a->c, b->c, b->a, c->a, c->b
// do DFS
#include <iostream>
#include <vector>
using namespace std;

int a, b, c, x;

void dfs(vector<vector<vector<bool>>> &ans, int aa, int bb, int cc) {
    if (ans[aa][bb][cc]) {
        return;
    }
    ans[aa][bb][cc] = true;
    // 6 possible moves : a->b, a->c, b->c, b->a, c->a, c->b
    // move 1: a->b
    x = min(aa, b-bb);
    dfs(ans, aa - x, bb + x, cc);
    // move 2: a->c
    x = min(aa, c-cc);
    dfs(ans, aa - x, bb, cc + x);
    // move 3: b->c
    x = min(bb, c-cc);
    dfs(ans, aa, bb - x, cc + x);
    // move 4: b->a
    x = min(bb, a-aa);
    dfs(ans, aa + x, bb - x, cc);
    // move 5: c->a
    x = min(cc, a-aa);
    dfs(ans, aa + x, bb, cc - x);
    // move 6: c->b
    x = min(cc, b-bb);
    dfs(ans, aa, bb + x, cc - x);
}

int main(void) {
    cin >> a >> b >> c;
    vector<vector<vector<bool>>> ans(21, vector<vector<bool>>(21, vector<bool>(21, false)));
    dfs(ans, 0, 0, c);
    for (int i = 0; i < c+1; i++) {
        for (int j = 0; j < c+1; j++) {
            if (ans[0][j][i]) {
                cout << i << " ";
            }
        }
    }
    return 0;
}
