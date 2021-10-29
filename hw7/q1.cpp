// Q1 Ski
/*
Desciption：
Michael likes ski as ski brings a lot of fun. In order to gain speed, the slide area has to be inclined. While you reach 
the bottom of the ski slope, you will have to walk back to the top of the slope, or wait for the lift to carry you back to 
top of the hill. 

Michael tries to find a longest path from a given ski area. The area is described by a 2-dimensional map/matrix which is 
represneted by a 2-D array. Each number in the array means the height of that spot. Below is an example:

1   2   3   4   5
16  17  18  19  6
15  24  25  20  7
14  23  22  21  8
13  12  11  10  9

One could slide down to neighboring up/down/left/right spots when and only when he is sliding down (i.e., height will 
decrease after move). In the example shown above, one possible ski route could be 24-17-16-1 (namely satrting from 24, 
going through 17, 16 and ending at 1). Of course the route of 25-24-23-...-3-2-1 will be even longer and in fact it is the 
longest route/path.

Input：
1st line has two integers, the row number R and column number C.
Then there are R lines. Each line has C numbers. These numbers describe the heights of those corresponding spots. Numbers 
are separated by a space.

Output：
One numner as the longest ski route/path within that given ski area.

Example Input：
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

Example Output：
25 

Constraints:
For 100% data input，1≤R,C≤100.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int r, int c, int &maxlen, int &len) {
    int temp = ans[r][c];
    if (temp) {
        maxlen = max(maxlen, len+temp);
        return;
    } else {
        len++;
    }

    maxlen = max(maxlen, len);
    for (int i = 0; i < 4; i++) {
        int x = r+dx[i], y = c+dy[i];
        if (x < 0 || y < 0 || x >= map.size() || y >= map[0].size() || map[x][y] >= map[r][c]) {
            continue;
        }
        dfs(x, y, maxlen, len);  
    }
    len--;    
}

int main(void) {
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        vector<int> row(C);
        for (int j = 0; j < C; j++) {
            cin >> row[j];
        }
        map.push_back(row);
        ans.push_back(vector<int>(C, 0));
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int max = 0, len = 0;
            dfs(i, j, max, len);
            ans[i][j] = max;
        }
    }

    int answer = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            answer = max(answer, ans[i][j]);
        }
    }    

    cout << answer;
    return 0;
}