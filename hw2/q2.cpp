/* Q2 Permutation
Time Limit：2s   Memory Limit：256M
 
Description
Input a postive integer N,output all the sequence made of 1 to N(N<=7),each line is a sequence,one blank 
between each two numbers. One sequence is former than another if its first number is smaller(if their first 
numbers are the same,then we compare the second number and so on). 

Input
One integer N.   

Output
All the sequences.

Sample Input
5 

Sample Output
1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3
1 3 2 4 5
1 3 2 5 4
1 3 4 2 5
1 3 4 5 2
1 3 5 2 4
1 3 5 4 2
1 4 2 3 5
1 4 2 5 3
1 4 3 2 5
1 4 3 5 2
1 4 5 2 3
1 4 5 3 2
1 5 2 3 4
1 5 2 4 3
1 5 3 2 4
1 5 3 4 2
1 5 4 2 3
1 5 4 3 2
2 1 3 4 5
2 1 3 5 4
2 1 4 3 5
2 1 4 5 3
2 1 5 3 4
2 1 5 4 3
2 3 1 4 5
2 3 1 5 4
2 3 4 1 5
2 3 4 5 1
2 3 5 1 4
2 3 5 4 1
2 4 1 3 5
2 4 1 5 3
2 4 3 1 5
2 4 3 5 1
2 4 5 1 3
2 4 5 3 1
2 5 1 3 4
2 5 1 4 3
2 5 3 1 4
2 5 3 4 1
2 5 4 1 3
2 5 4 3 1
3 1 2 4 5
3 1 2 5 4
3 1 4 2 5
3 1 4 5 2
3 1 5 2 4
3 1 5 4 2
3 2 1 4 5
3 2 1 5 4
3 2 4 1 5
3 2 4 5 1
3 2 5 1 4
3 2 5 4 1
3 4 1 2 5
3 4 1 5 2
3 4 2 1 5
3 4 2 5 1
3 4 5 1 2
3 4 5 2 1
3 5 1 2 4
3 5 1 4 2
3 5 2 1 4
3 5 2 4 1
3 5 4 1 2
3 5 4 2 1
4 1 2 3 5
4 1 2 5 3
4 1 3 2 5
4 1 3 5 2
4 1 5 2 3
4 1 5 3 2
4 2 1 3 5
4 2 1 5 3
4 2 3 1 5
4 2 3 5 1
4 2 5 1 3
4 2 5 3 1
4 3 1 2 5
4 3 1 5 2
4 3 2 1 5
4 3 2 5 1
4 3 5 1 2
4 3 5 2 1
4 5 1 2 3
4 5 1 3 2
4 5 2 1 3
4 5 2 3 1
4 5 3 1 2
4 5 3 2 1
5 1 2 3 4
5 1 2 4 3
5 1 3 2 4
5 1 3 4 2
5 1 4 2 3
5 1 4 3 2
5 2 1 3 4
5 2 1 4 3
5 2 3 1 4
5 2 3 4 1
5 2 4 1 3
5 2 4 3 1
5 3 1 2 4
5 3 1 4 2
5 3 2 1 4
5 3 2 4 1
5 3 4 1 2
5 3 4 2 1
5 4 1 2 3
5 4 1 3 2
5 4 2 1 3
5 4 2 3 1
5 4 3 1 2
5 4 3 2 1
*/
#include <iostream>
#include <vector>
using namespace std;

void swap1(vector<int> &input, int i, int j) {
    int temp = input[i];
    for (int x = i; x > j; x--) {
        input[x] = input[x-1];
    }
    input[j] = temp;
}

void swap2(vector<int> &input, int i, int j) {
    int temp = input[j];
    for (int x = j; x < i; x++) {
        input[x] = input[x+1];
    }
    input[i] = temp;
}

void printAllPermutations(vector<int> input, int index) {
    if (index >= input.size()-1) {
        for (int x : input) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = index; i < input.size(); i++) {
        swap1(input, i, index);
        printAllPermutations(input, index+1);
        swap2(input, i, index);
    }    
}

int main(void) {
    int n;
    cin >> n;
    vector<int> input;
    for (int i=1; i<=n; i++) {
        input.push_back(i);
    }
    printAllPermutations(input, 0);
    return 0;    
}