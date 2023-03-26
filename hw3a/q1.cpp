// A. Combinations divisible by K
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6393&fragments=11612&problemId=9187&pattern=0
/*
Given some integer value n, find all the combinations that summed are divisible by some integer value k. This is to take n numbers 
from 1, 2, 3, ..., n, and the sum can be divided by k. Duplicates are allowed. Please output the combinations based on dictionary 
order (lexicographic order). For example, the following random number combinations are sorted on dictionary order.
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
Note that these combinations are used to demo dictionary order. They are not related to the problem.

Input:
Two space separated integers n, k. 

Output:
All combinations whose sum is divisible by k. 

Sample Input:
3 8

Sample Output: 
2 3 3
3 2 3
3 3 2

1 <= n <= 10
Hint - Combinations allow duplicates. For example combinations of numbers 1-3 can be 1 1 1, 1 1 2, 1 2 1 etc. 
*/
#include <iostream>

using namespace std;

int n;
int k;
int print_num[11];

void comb(int ball_processed) {

  int sum=0;
  
  if (ball_processed == n) {
    
    for (int i = 0; i < n; i++) {
      sum += print_num[i]; 
    }
    
    if (sum % k == 0){
      for (int i = 0; i < n; i++) {
       cout << print_num[i] << " ";
    }
      cout << endl;
    }

    sum=0;
    
    return;
  }
  
  for (int i = 0; i < n; i++) {
    print_num[ball_processed] = i + 1;
    comb(ball_processed + 1);
  }
  
}

int main()
{
  cin >> n >> k;
  comb(0);
}
