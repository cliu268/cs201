// Q3 Red and Black
/* 
time limit：1   memory limit：512M 

description：
A rectangular room is covered by square tiles. The tile is either red or black. A man stand on a black tile, and he 
can move to one of the adjacent four tiles. He can only move on the black tiles, but not the red ones.
Write a program to calculate the number of black tiles he can reach.

Input：
Input consists of several data set starting with a line which contains two positive integers W and H. W and H are the 
numbers of tiles on x and y directions. The sum of W and H does not exceed 20.
There are H lines in the data set, each line contains W characters. Each character represents the color of the tile. 
'' - black tile
'＃' - red tile
'@' - man on the black tile (appear only once in the data set)
When W and H equal to 0 , it means the end of input.

Output：
the number of black tiles he can reach (including the original one).

Sample input 1：
6 9
....#.
.....#
......
......
......
......
......
#@#...
.###..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0

Sample output 1：
45
13
*/
// same question as hw5 q2, refer to https://github.com/cliu268/cs201/blob/main/hw5/q2.cpp