// Q1 Super Shelf 2
/*
Time limit：1   Memory limit：32M 

Description：
Farmer John recently bought a book shelf. It was filled with books with only the top available. 
Now there are N (1 <= N <= 20) cows with height H_i (1 <= H_i <= 1,000,000). Suppose the sum of their height is S and 
the height of the shelf is B (1 <= B <= S). The cows have to stand on each other to reach the top of the book shelf. 
The height of the cow tower is the sum of their height. The higher the tower, the less stable it will be. So the cows 
want to find a solution such that when the height of the tower is no less than the shelf's height, the tower height can 
be as small as possible. Please design a program to find out at least how much higher the cow tower should be than the shelf.

Input：
The first line contains two integers N and B (separated by space)
The second to the N+1 line: the i+1 line contains an integer H_i

Output：
The first line contains a non-negative integer, which is the smallest difference between the height of the milk tower 
and the shelf.

Sample input 1：
5 16
3
1
3
5
6

Sample output 1：
1

Note：
1<=n<=20
1<=H_i<=1000000
*/
// same question as hw5 q1, refer to https://github.com/cliu268/cs201/blob/main/hw5/q1.cpp
