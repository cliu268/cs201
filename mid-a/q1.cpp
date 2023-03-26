// A. Triple Fibonacci
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6566&fragments=11647&problemId=9655&pattern=0
/*
Similar to the fibonacci seuqence we have seen defined in lecture, we can define a triple fibonacci sequence.
In the triple fibonacci number sequence, each number is the sum of previous three numbers.

i.e.
f(1)=1,f(2)=1,f(3)=1
f(n)=f(n−1)+f(n−2)+f(n−3)
Given n, please output the coresponding triple Fibonacci number. For instance, given n =5, output the value of f(5).

Sample input
5

Sample output
5
*/
#include <iostream>
using namespace std;

int f(int a){
  if(a==1 || a==2 || a==3){
    return 1;
  }
  else{
    return f(a-1) + f(a-2) + f(a-3);
  }
}

int main() {
  int x;
  cin >> x;
  cout << f(x) << endl;
}