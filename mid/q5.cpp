// Q5 Matrix with Treasures I
/* 
Time limit：1s   
Space limit: 128M
Description：
Explorers in the country of X recently discovered some ruins. It is like a matrix but it has a lot of treasures.

Explorers figured out the map of this matrix using an "Eagle Eyes" detector. This is a 2D map. '#' means a trap 
which by no means can be gone through. '*' means an accesible spot. Some spots have treasures there, whose value 
is indicated by a number. 

The unique thing about this matrix is that once you pass a spot that spot will disappear. So basically you can not 
reach the same spot again.

The explorers wanted to know how many treasures they can get by maximum if they enter from upper left entrance and 
exit from lower right exit.

Input：
1st line has two integers n and m to describe the matrix size.
Then there will be n lines, each line has m characters. These lines/row describe the map. 
Make sure you do not have a trap on the extrance. 

Output：
One integer number, which is the max value the explorer can obtain. 
if you cannot get to the exit, output -1.

Sample Input：
5 6 
1****# 
*###2# 
4###*# 
*###1# 
**1***

Sample Output ：
6

Notes：
1 <= N，M<= 7，0<=each treasure<=9
*/
#include <iostream>
#include <vector>
using namespace std;

vector<string> maze;
vector<vector<bool>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int &max, int &count) {
    if (x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size() || visited[x][y] || maze[x][y] == '#') {
        return;
    }
    if (x == maze.size()-1 && y == maze[0].size()-1) {
        int end = 0;
        if (isdigit(maze[x][y])) {
            end = maze[x][y] - '0';        
        }
        if (count + end > max) {
            max = count + end;
        }
        return;
    }
    int temp = -1;
    if (isdigit(maze[x][y])) {
        temp = maze[x][y] - '0';
        count += temp;        
    }        
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int r = x+dx[i], c = y+dy[i];
        dfs(r, c, max, count);
    }
    visited[x][y] = false;
    if (temp > 0) {
        count -= temp;
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        maze.push_back(row);
        vector<bool> row2(m, false);
        visited.push_back(row2);
    }
    int max = -1, count = 0;
    dfs(0, 0, max, count);
    cout << max;
    return 0;
}