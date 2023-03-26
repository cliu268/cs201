// B. Collecting Inputs
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6390&fragments=11610&problemId=9378&pattern=0
/*
For some problems, you might need to run an infinite loop to collect input. You might not know how many inputs you are going to 
receive in a single line, or how many lines of input you might receive. 

To continually collect an input a in C++, you can use:

while (cin >> a) ...

This will stop running once you reach the end of input.

In python, similarly you can place your code in a while true loop:

while True:

    a = input()

Now, when trying to collect two inputs at a time, that are both numbers, you can do:

a, b = map(int, input().split())

This takes the input, splits it at space, converts each of the strings into integers, and then assigns the first to the a variable 
and the other to the b variable. 

Try this with the following problem:

【 Description 】  
Your task is to compute A plus B.  
The input will consist of A pair of integers A and B, separated by Spaces, one pair of integers per line. 
The input will be multiple lines  (All data in int range)  

【Sample input】
1 5
10 20

【Sample output】
6
30
*/
#include <iostream>
using namespace std;

int main() {
  int a;
  int b;
  while (cin >> a >> b){
    cout << a+b << endl;
  }
}