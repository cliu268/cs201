// Q2 Red and Black
/*
Description：
A rectangular room is covered by square tiles. The tile is either red or black. A man stand on a black tile, 
and he can move to one of the adjacent four tiles. He can only move on the black tiles, but not the red ones.
Write a program to calculate the number of black tiles he can reach.

Input：
Input consists of several data set starting with a line which contains two positive integers W and H. W and H 
are the numbers of tiles on x and y directions. The sum of W and H does not exceed 20.
There are H lines in the data set, each line contains W characters. Each character represents the color of the 
tile. 
'.' - black tile
'#' - red tile
'@' - man on the black tile (appear only once in the data set)
When W and H equal to 0 , it means the end of input.

Output：
the number of black tiles he can reach (including the original one).

Sample input 1：
6 9
....#.
.....#
......
......
......
......
......
#@#...
.###..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0

Sample output 1：
45
13

Time limit：1  Memory limit：512M
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(vector<string> &input, int x, int y, int &count) {
    count++;
    input[x][y] = '@';
    for (int i = 0; i < 4; i++) {
        int r = x+dx[i], c = y+dy[i];          
        if (r < 0 || c < 0 || r >= input.size() || c >= input[0].size()) continue;      
        if (input[r][c] == '#' || input[r][c] == '@') continue;  
        dfs(input, r, c, count);        
    }
}

int main(void) {
    int W, H;
    queue<vector<string>> maze;
    cin >> W >> H;    
    while (W * H != 0) {
        vector<string> input;
        for (int i = 0; i < H; i++) {
            string row;
            cin >> row;
            input.push_back(row);
        }
        maze.push(input);
        cin >> W >> H;
    }

    while (!maze.empty()) {
        vector<string> input = maze.front();
        maze.pop();
        int x, y, count;
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[0].size(); j++) {
                if (input[i][j] == '@') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        count = 0;
        dfs(input, x, y, count);
        cout << count << '\n';
    }
    return 0;
}