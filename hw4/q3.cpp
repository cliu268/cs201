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
*/
#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<int>> board, int row, int col, int count) {
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || 
        (board[row][col] != -1 && count >= board[row][col])) { // allow override if count is smaller
        return false;
    }
    return true;
}

void traverse(vector<vector<int>> &board, int sr, int sc, int &count) {
    if (!isValid(board, sr, sc, count)) {
        return;
    }  

    board[sr][sc] = count;
    count++;
    
    // 8 ways to traverse
    int move[8][2] = {{1,2}, {2,1}, {-1,-2}, {-2,-1}, {1,-2}, {-2,1}, {-1,2}, {2,-1}};
    for (int i = 0; i < 8; i++) {
        traverse(board, sr+move[i][0], sc+move[i][1], count);
    }
    
    count--;
}

void printBoard(vector<vector<int>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            printf("%-*d", 5, board[i][j]);
        }
        cout << "\n";
    }    
}

int main(void) {
    int n, m, sr, sc;
    cin >> n >> m >> sr >> sc;
    vector<vector<int>> board(n);
    for (int i = 0; i < n; i++) {
        vector<int> row(m, -1);
        board[i] = row;
    }
    int count = 0;
    traverse(board, sr-1, sc-1, count);
    printBoard(board);
    return 0;
}