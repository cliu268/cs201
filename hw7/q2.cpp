// Q2 I am Autistic
/*
Time：0.2 
Space：32M

Description：
You will become autistic if you fall into the sea of excrescence. But Boy Ma won't.
Boy Ma gives you a map of the Sea of Excrescence. It has n rows (from 1 to n) and m columns (from 1 to m). Two spots are 
connected if they are neighbors. An example: (x,y) is connected to (x,y), (x-1,y), (x+1,y), (x,y-1) and (x,y+1) only. 

Every spot could have an excrescence (spot has a value of 1) or not (value=0). 
Let's define the so-called Excrescence Block. A Excrescence Block is an area where any two spots of excrescence can reach 
each other through their neighbors.

Now please find out how many spots with excrescence can a biggest Excrescence Block have.
You may need to refer to the samples for better understanding of the questions.

Input：
The first line has two numbers n and m.
Then there are n lines, each line has m numbers. Those numbers are either 1 or zero.

Output：
One number.

Sample Input1：
5 4
0101
0111
1000
1100
0101

Sample Output1：
5

Notes：
1<=n, m<=50
*/
#include <iostream>
#include <vector>
using namespace std;

vector<string> map;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int maxblock = 0;

void floodfill(int x, int y, int &count) {
    count++;
    map[x][y] = '0';
    for (int i = 0; i < 4; i++) {
        int r = x+dx[i], c = y+dy[i];
        if (r < 0 || c < 0 || r >= map.size() || c >= map[0].size() || map[r][c] == '0') {
            continue;
        }
        floodfill(r, c, count);
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    string row;
    for (int i = 0; i < n; i++) {
        cin >> row;
        map.push_back(row);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '0') {
                continue;
            } else {
                int count = 0;
                floodfill(i, j, count);
                maxblock = max(maxblock, count);
            }
        }
    }
    cout << maxblock;
    return 0;
}