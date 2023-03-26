// E. Merge Sort
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6390&fragments=11610&problemId=9185&pattern=0
/*
Use the merge sort algorithm to sort the list of integers. 

Input
The first line is n, representing the number of integers in the list
The second line contains n space separated integers

Output
n space separated integers in sorted order

Sample Input
5
5 2 1 4 3

Sample Output
1 2 3 4 5 
*/
// XCamp answer
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>& v, int start, int end) {
    if (end - start > 1) {
        int n = end - start, mid = (start + end) / 2;
        merge_sort(v, start, mid);
        merge_sort(v, mid, end);
        vector<int> merged(n);
        for (int i = start, j = mid, k = 0; i < mid || j < end; k ++) {
            if (j >= end || i < mid && v[i] < v[j]) {
                merged[k] = v[i ++];
            } else {
                merged[k] = v[j ++];
            }
        }
        std::copy(merged.begin(), merged.end(), v.begin() + start);
//        for (int i = 0; i < n; i ++) {
//            v[start + i] = merged[i];
//        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i ++) {
        cin >> v[i];
    }
    merge_sort(v, 0, n);
    for (int x : v) {
        cout << x << " ";
    }
    return 0;
}
/*
5
5 2 1 4 3
 */