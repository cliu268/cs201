/* Q3 Nth Number
Description
Sequence A1,A2,A3,A4,…,A20 。

Now we know:
A1=0
A2=1
A3=1
A4=A1+2∗A2＋A3
A5=A2+2∗A3+A4
......

Calculate An 

Input
Integer n.  1<=n<=20

Output
Integer An.

Sample Input
4
Sample Output
3
*/
#include <iostream>
#include <vector>
using namespace std;

int nthNumber(int n) {
    if (n == 0 || n == 1) {
        return 0;
    } else if (n == 2 || n == 3) {
        return 1;
    } else {
        vector<int> ans(n+1);
        ans[0] = ans[1] = 0;
        ans[2] = ans[3] = 1;
        for (int i = 4; i <= n; i++) {
            ans[i] = ans[i-1] + 2*ans[i-2] + ans[i-3];
        }
        return ans[n];
    }
}

int main(void) {
    int n;
    cin >> n;
    cout << nthNumber(n) << endl;
}
