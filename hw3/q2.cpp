// Q2 Social Circle
/*
Problem Statement
There are n students in class. Some of them are friends, and some of them are not. Friendship has transitivity. 
For example, if A is B's friend, and B is C's friend, and A will be C's friend as a result of transitivity. 
So-called social circle, means a set of people who are all friends to each other. Note that there could be 
multiple social circles.

Given a n by n matrix M, representing the friendships in class. If M[i][j] = 1, i-th student and j-th student 
are friends to each other; otherwise their relationship is unknown (with transitivity students could be friends 
even they are not friends directly). Please compute the number of social circles in total.

Input Format
The first line is n. (1<=n<=200)
Over the next n lines, we will have n integer each line, and each integer is 1 or 0.

Output Format
One integer representing total number of social circles.

Sample Input：
3
1 1 0
1 1 1
0 1 1

Sample Output：
1

Sample Input:
5        
1 1 1 0 0
1 1 0 1 0
1 0 1 0 0
0 1 0 1 0
0 0 0 0 1

Sample Output:
2
*/
#include <iostream>
#include <vector>
using namespace std;
void findFriends(vector<bool> &visted, vector<vector<int>> friends, int index) {
    for (int i = 0; i < visted.size(); i++) {
        if (i == index || visted[i]) continue;
        if (friends[index][i] == 1) {
            visted[i] = true;
            findFriends(visted, friends, i);
        }
    }
}

int socialCircle(vector<vector<int>> friends) {
    vector<bool> visted(friends.size(), false);
    int numCircles = 0;
    for (int i = 0; i < friends.size(); i++) {
        if (!visted[i]) {
            visted[i] = true;
            numCircles += 1;
            findFriends(visted, friends, i);
        }
    }
    return numCircles;
}

int main(void){
    int n;
    cin >> n;
    vector<vector<int>> friends(n);
    for (int i = 0; i < n; i++) {
        vector<int> row(n);
        for (int j = 0; j < n; j++) {
            cin >> row[j];
        }
        friends[i] = row;
    }
    cout << socialCircle(friends);
    return 0;
}