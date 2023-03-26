// C. Ski
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6568&fragments=11884&problemId=9562&pattern=0
// Same in hw7 q1.cpp
/*
Desciption：
Michael likes skiing as skiing is very fun. In order to gain speed, the skiing area has to be inclined. While you reach the bottom of the ski slope, 
you will have to walk back to the top of the slope, or wait for the lift to carry you back to top of the hill. 

Michael is trying to find the longest path in a given ski area. The area is described by a 2-dimensional map/matrix which is represneted by a 2-D array. 
Each element in the array indicates the height of that spot. Below is an example:

1   2   3   4   5
16  17  18  19  6
15  24  25  20  7
14  23  22  21  8
13  12  11  10  9

Michael can ski down to neighboring spots (no diagonals) when and only when he is skiing down (i.e., height will decrease after moving). 
In the example shown above, one possible ski route could be 24-17-16-1 (namely starting from 24, going through 17, then going through 16, and ending at 1). 
Of course, the route of 25-24-23-...-3-2-1 will be even longer and in fact it is the longest route/path.

Input：
1st line has two integers, the row number R and column number C.
Then there are R lines. Each line has C numbers. These numbers describe the heights of those corresponding spots. Numbers are separated by a space.

Output：
One number as the longest ski route/path within that given ski area.

Sample Input：
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

Sample Output：
25

Constraints:
For 100% data input，1≤R,C≤100.
*/
#include <iostream>
#include <vector>
using namespace std;
int r, c;
int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};
vector<vector<int>> graph(101, vector<int>(101));
int ans=0;
void dfs(int x, int y, int count) {
    ans=max(ans, count);
    for (int i=0; i<4; i++) {
        int newx=x+dx[i]; int newy=y+dy[i];
        if (newx<0 || newy<0 || newx>=r || newy>=c) {
            continue;
        }
        if (graph[newx][newy]>=graph[x][y]) {
            continue;
        }
        dfs(newx, newy, count+1);
    }
}
int main() {
    cin>>r>>c;
    int maxi=0; int mx=0; int my=0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin>>graph[i][j];
        }
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            dfs(i, j, 1);
        }
    }
    cout<<ans;
}