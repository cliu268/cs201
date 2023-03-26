// A. Welcome to XJOI
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6390&fragments=11610&problemId=9474&pattern=0
/*
Welcome to X-Camp's autograder, "XJOI". XJOI takes input and output differently to other programs similar to it. 

Python
If you want to use python, note that there's a chance that you could run into TLE when performing recursion. Also, Python's IO is 
slower than that of other languages such as C++. Despite this, we support the lanauge as long as you follow the following guidelines.
1. If you want to input a single string: s = input()
2. If you want to input a single int: n = int(input())
3. If you want to input a list of strings strs = input().split()
4. If you want to input an integer list nums = list(map(int, input().split()))
5. The output should match the example, exactly. 

C++
This is the language we support the best. We highly recommend you use C++ if able to, as it is the most popular lagnuage in 
competitve programming.

Java
Whilst we support the use of Java, it is not recommended. If you decide to use it, you should use the following boilerplate code:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class program {
    public static void main(String[] args) throws IOException{
        // your code here
  }
}

Note that you must use the class name "program", all with lower case

Now, given your language of choice, 
Write a small program to make friends with the computer:
(NOT including quotation marks)
First, the computer asks: "Hello, what is your name?"
Then you enter your name.
Finally, the computer replies: "Nice to meet you, XXX" (XXX is the name you entered, no space after the XXX)

Input:
A string representing your name

Output: 
See sample output

Sample Input/Output:
Output:
Hello, what is your name?

Input on the same line:
Lucy

Output:
Nice to meet you, Lucy
*/
#include <iostream>
using namespace std;

int main() {
  string n;
  cout << "Hello, what is your name?";
  cin >> n;
  cout << "Nice to meet you, " << n << endl;
}