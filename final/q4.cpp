// Q4 Grouping the students
/*
Time limit：1s   Memory limit：128M 

Description：
There are N groups of students. Given the initial number of students in each group, and the upper bound R and lower 
bound L of the number of students in a group (L≤R), you can pick one student from a certain group and move him/her 
in another group. Please find out at least how many moves does it take for the number of students in all the N groups 
to be within [L,R].

Input：
The first line contains an integer N, representing the number of groups. n≤50
The second line contains N integers, representing the number of students in each group.
The third line contains two integers L and R, representing the upper and lower bound.

Output：
a number which means the least time it takes.
If there is no answer, print -1.

Sample input 1：
2
10 20
10 15

Sample output 1：
5
*/
// count if total can fit, if not, print -1, if yes, print max(total < lower bound, total > upper bound)
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, l, r, total = 0;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        total += s[i];
    }
    cin >> l >> r;    
    if (total < l*n || total > r*n) {
        cout << -1;
        return 0;
    }

    int ll = 0, rr = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] < l) {
            ll += l - s[i];
        }
        if (s[i] > r) {
            rr += s[i] - r;
        }
    }
    cout << max(ll, rr);
    return 0;        
}