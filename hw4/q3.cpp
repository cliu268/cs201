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

void traverse(vector<vector<int>> &board, int n, int m, int sr, int sc) {
    // for (int i = 0; i < board.size(); i++) {
    //     for (int j = 0; j < board[i].size(); j++) {
    //         board[i][j] = sr*(-1);
    //     }
    // }    
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
        vector<int> row(m, 0);
        board[i] = row;
    }
    traverse(board, n, m, sr, sc);
    printBoard(board);
    return 0;
}