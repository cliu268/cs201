/* Q4 Triangle Counting
Divide each side of the large triangle by n and connect the corresponding bisectors (the lines are parallel 
to the three sides). How many triangles there will be? Programming to solve this problem.

Input:
Integer n where 1<=n<=10000

Output:
Integer indicating the number of triangles

Sample input 1:
3
Sample output 1:
13

*/
#include <iostream>
#include <vector>
using namespace std;

long long triangleCounting(int n) {
    vector<long long int> ans(n);
    ans[0] = 1;
    for (long long i = 1; i < n; i++) { // note that array starts with index 0, meaning i = n-1
        if (i% 2 == 0) {
            ans[i] = ans[i-1] + (i+2)*(i+1)/2 + (i+2)*i/4;
        } else {
            ans[i] = ans[i-1] + (i+2)*(i+1)/2 + (i+1)*(i+1)/4;
        }
    }
    return ans[n-1];
}

int main(void) {
    int n;
    cin >> n;
    cout << triangleCounting(n) << endl;
    //printf("%llu", triangleCounting(n));
    return 0;
}
