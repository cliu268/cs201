// Q3 Horse Traversal
/*
Title description:
There is an n*m chessboard (1<n,m<=400), there is a horse at a certain point, and you are required to 
calculate the minimum number of steps the horse has to take to reach any point on the chessboard

Input format:
Four data in one row, the size of the chessboard and the coordinates of the horse

Output format:
An n*m matrix, representing that the horse has to walk at least a few steps to reach a certain point (aligned 
to the left, 5 grids wide, output -1 if it can't reach it)

Sample Input:
3 3 1 1

Sample Output：
0    3    2    
3    -1   1    
2    1    4 

Sample Input2:
168 100 69 18 

Sample Output2:
*** super large, if not efficient, this will fail ***
*/
#include <iostream>
#include <vector>
using namespace std;

// 8 ways to traverse
int dirx[8] = {1, 2, -1, -2, 1, -2, -1, 2};
int diry[8] = {2, 1, -2, -1, -2, 1, 2, -1};
vector<vector<int>> board;

bool isValid(int row, int col, int count) {
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || 
        (board[row][col] != -1 && count >= board[row][col])) { // allow override if count is smaller
        return false;
    }
    return true;
}

void traverse(int sr, int sc, int &count) {
    if (!isValid(sr, sc, count)) {
        return;
    }  

    board[sr][sc] = count;
    count++;
    
    for (int i = 0; i < 8; i++) {
        traverse(sr+dirx[i], sc+diry[i], count);
    }
    
    count--;
}

int main(void) {
    int n, m, sr, sc, count = 0;
    cin >> n >> m >> sr >> sc;
    for (int i = 0; i < n; i++) {
        vector<int> row(m, -1);
        board.push_back(row);
    }
    traverse(sr-1, sc-1, count);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            printf("%-*d", 5, board[i][j]);
        }
        cout << "\n";
    } 
    return 0;
}