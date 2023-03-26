// B. Lake Counting
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6397&fragments=11614&problemId=8014&pattern=0
// Same question in mid q4.cpp
/*
Description：
Because of the recent heavy rain, water has gathered in Farmer's John's field, which is represented by a N x M grid. Cells with a value of '1' mean 
they are covered in water and '0' means dry land. A cell is connected to its neighboring eight cells. A group of connected cells is considered a pool. 
Farmer John needs to figure out how many pools there are in the field. Given the illustration of the field, please find the number of pools.

Input：
The first line: two integers N and M (separated by space)
The second to the N+1 line：each line contains M characters of '1' or '0', which means a row in the grid. Those characters are not separated by space.

Output：
The number of pools. 

Sample input：
5 5
10011
10010
11011
01000
11010

Sample output：
3

Constraints:
1 <= N <= 100; 1 <= M <= 100
*/