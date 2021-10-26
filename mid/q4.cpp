// Q4 Lake Counting
/*
Time limit：1   Memory limit：32M

Description：
Because of the recent heavy rain, water gathered in farmer's John's field, which is represented by a NxM(1<=N<=50;1<=M<=50) 
grid. Cells with '1' mean there is water. '0' means dry land. A cell is connected to the surrounding eight cells. A group 
of connected cells is considered a pool. John wants to figure out how many pools there are in the field. Given the 
illustration of the field, please find the number of pools.

Input：
The first line: two integers N and M (separated by space)
The second to the N+1 line：each line contains M characters of '1'or'0', which means a row in the grid. Those characters 
are not separated by space.

Output：
the number of pools

Sample input 1：
5 5
00111
10000
11000
00011
11100

Sample output 1：
3

Note：
1<=n<=100
*/
#include <iostream>
#include <vector>
using namespace std;

vector<string> map;

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void solve(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int r = x+dx[i], c = y+dy[i];
        if (r < 0 || c < 0 || r >= map.size() || c >= map[0].size()) continue;
        if (map[r][c] != '0' && map[r][c] != '2') {
            map[r][c] = '2';
            solve(r, c);    
        }
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

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != '0' && map[i][j] != '2') {
                count++;
                map[i][j] = '2';
                solve(i, j);
            }
        }
    }
    cout << count;
    return 0;
}