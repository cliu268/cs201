// Q1 Run away
/*
Time limit：1s   memory limit：128M

Description：
Ignatius was caught by a devil. One day, the devil is out. This is a great opportunity for Ignatius to run away.
The devil lives in a castle represented by a A*B*C cube (or A B*C matrices). At first, Ignatius is kept in (0,0,0). 
The exit is in (A-1,B-1,C-1). The devil will return to the castle in T minutes, and Ignatius can walk to one of the 
adjacent six coordinates in one minute. Please find out if Ignatius can leave the castle before the devil returns (as 
long as he can reach the exit, he can leave, even if the devil returns at exactly that time). If he can leave, print 
the time he needs. Otherwise, print -1.

Input：
The first line contains a positive integer K, the number of test data.
In each group of test data:
The first line contains four positive integers A,B,C and T(1<=A,B,C<=50,1<=T<=1000), --- the size of the castle and 
the time the devil will return. Then describe the layout of the castle (B lines, C positive integers in each line). 
0 means road, 1 means wall. See sample input.

Output：
If Ignatius can leave, print the minimum time he needs. Otherwise, print -1.

Sample input 1：
1
3 3 4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0

Sample output 1：
11
*/