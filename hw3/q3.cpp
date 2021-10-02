// Q3 Floodfill
/*
Count how many cells can be reached within a N by N maze, with a start point, and with the rule that each 
step you can move up, down, top-left, bottom-right for one step. 

Input format:
Three integers in the first line, representing N, and location of start point.
Next N lines: each line has N 0/1 separated by space, where 0 represents the position you may fill, and 1 
represents the barrier. (1<=N<=500)

Output format:
Single integer representing number of cells you can reach.

Sample input:
3 0 0
0 0 0
0 1 0
1 0 1

Sample output:
3
*/
#include <iostream>
#include <vector>
using namespace std;

void floodFill(vector<vector<int>> &input, int x, int y, int &visted) {
    // for (int i = 0; i < input.size(); i++) {
    //     for (int j = 0; j < input.size(); j++) {
    //         cout << input[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    if (0 <= x && x < input.size() && 0 <= y && y < input.size() && input[x][y] == 0) {
        visted += 1;
        input[x][y] = 1;
        // move up
        floodFill(input, x-1, y, visted);
        // move down
        floodFill(input, x+1, y, visted);
        // move top-left
        floodFill(input, x-1, y-1, visted);
        // move bottom-right
        floodFill(input, x+1, y+1, visted);
    }
}

int main(void) {
    int n,x,y;
    cin >> n >> x >> y;
    vector<vector<int>> input(n);
    for (int i = 0; i < n; i++) {
        vector<int> row(n);
        for (int j = 0; j < n; j++) {
            cin >> row[j];
        }
        input[i] = row;
    }
    int visted = 0;
    floodFill(input, x, y, visted);
    cout << visted;
    return 0;
}