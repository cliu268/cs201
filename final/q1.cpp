// Q1 Sort of Test Score
/*
Input the names and scores of Chinese and Math tests for N students. Then sort the total scores (sum) in descent order. 
For students with the same scores , their positions will be decided by the time order when their scores are input. 

Input Format:
1st line has one integer N (N in [1,100]).
Then there are N lines for N student. Each line has one character for student's name and two integers for the scores 
of Chinese and math tests. Student's name contains no more 10 lower case letters. The score integers will be in [0,100].

Output Format:
Name list of N lines, sorted by the total scores (sum). Each line has name, Chinese Test Score, Math Test score, and 
Total Score, each separated by two spaces.

Sample Input：
4
gaoxiang  78  96
wangxi  70  99
liujia  90  87
zhangjin  78  91

Sample Output：
liujia  90  87  177
gaoxiang  78  96  174
wangxi  70  99  169
zhangjin  78  91  169
*/

// #include <bits/stdc++.h>
// using namespace std;
 
// vector<string> students;
// vector<vector<int>> scores;
// int main() {
//   int n; cin>>n;
//   for (int i=0; i<n; i++) {
//     string s; cin>>s;
//     students.push_back(s);
//     int a, b; cin>>a>>b;
//     scores.push_back({a,b});
//   }
//   vector<int> sums;
//   for (int i=0; i<n; i++) {
//     sums.push_back(scores[i][0]+scores[i][1]);
//   }
//   vector<bool> visited(n, false);
//   sort(sums.begin(), sums.end());
//   for (int i=n-1; i>=0; i--) {
//     for (int j=0; j<n; j++) {
//       if ((scores[j][0]+scores[j][1]==sums[i]) && (!visited[j])) {
//         cout<<students[j]<<" "<<scores[j][0]<<" "<<scores[j][1]<<" "<<sums[i]<<"\n";
//         visited[j]=true;
//       }
//     }
//   }
// }

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct student {
  string name;
  int chinese, math, total, index;
};

bool compS(student a, student b) {
    if (a.total > b.total) {
        return true;
    } else if (a.total == b.total) {
        return a.index < b.index;
    }
    return false;
}

int main(void) {
    int n;
    cin >> n;
    vector<student> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].name >> s[i].chinese >> s[i].math;
        s[i].total = s[i].chinese + s[i].math;
        s[i].index = i;
    }
    sort(s.begin(), s.end(), compS);
    for (auto it: s) {
        cout << it.name << "  " << it.chinese << "  " << it.math << "  " << it.total << "\n";
    }
}