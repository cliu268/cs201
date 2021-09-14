/* Q2 Digital Triangle
Description :
Digital triangle. Shown below is a number triangle. Please make a program to calculate a path somewhere from 
the top to the bottom, so that the sum of the numbers passed by the path is the largest. 
Only the sum is required to output.

1. One step can go straight down or right down;
2. The number of triangle rows is less than or equal to 100;
3. The numbers in the triangle are 0, 1, ..., 99;

The test data is input line by line through the keyboard. For example, the data should be entered in 
the following format: (in this example, the path should be 7->3->8->7->5 and the sum is 30)
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

Input :
The first line enters an integer N to indicate the height of the tower.
Next N lines, the i-th line has i integers

Output :
 an integer

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
#include <algorithm>
using namespace std;

int digitalTriangle(int ** ans, int n) {
    if (n == 1) {
        return ans[0][0];
    } else {
        for (int i = 1; i < n; i++) {
            ans[i][0] += ans[i-1][0];
            for (int j = 1; j < i; j++) {
                ans[i][j] += max(ans[i-1][j-1], ans[i-1][j]);
            }
            ans[i][i] += ans[i-1][i];
        }
        //return *max(ans[n-1], ans[n-1] + n);
        return 0;
    }
}

int main(void) {
    int n;
    cin >> n;
    int ** ans = new int*[n];
    for (int i = 0; i < n; i++) {
        ans[i] = new int[i+1];
        for (int j = 0; j < i+1; j++) {
            cin >> ans[i][j];
        }
    }

    cout << digitalTriangle(ans, n) << endl;

    // print the 2D array
    cout << "Print 2D array" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i+1; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }    

    // deallocate memory using the delete operator
    for (int i = 0; i < n; i++) {
        delete[] ans[i];
    }
    delete[] ans;    
}