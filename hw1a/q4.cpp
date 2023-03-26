// D. Triangle of Numbers
//https://www.xinyoudui.com/contest?courses=350&books=253&pages=6390&fragments=11610&problemId=3657&pattern=0
/*
Time limit: 1s, Memory limit: 128M

Description:
Digital triangle. Shown below is a number triangle. Please write a script to find out a path somewhere from the top to the bottom, 
so that the sum of the numbers on the path is the largest. Only the sum  is required in the output.
1. Every step can go straight down or right down (diagonal);
2. The number of triangle rows is less than or equal to 100;
3. The numbers in the triangle rows are 0, 1, ..., 99;

The Triangle of Numbers is input line by line through the keyboard. For example, the data should be entered in the following format: 
(in this example, the path should be 7->3->8->7->5 and the sum is 30)
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

Input:
The first line is an integer N to indicate the height of the tower (i.e., the row number of the Trianles of Numbers).
Then followed by N lines, the i-th line has i integers. Each line is a row for the Triangle.

Output:
One integer number.

Sample input:
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

Sample output:
30
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
  
    vector<vector<int>> numbers;
  
    for(int i=0; i<n; i++){
        vector<int> row;
    
        for (int j=0; j<i+1; j++) {
            int xx;
            cin >> xx;
            row.push_back(xx);
        }
    
        numbers.push_back(row);
    }

    for(int i=n-2; i>=0; i--) {
        for(int j=0; j<i+1; j++) {
            numbers[i][j] += max(numbers[i+1][j], numbers[i+1][j+1]);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << numbers[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << numbers[0][0] << endl;
}