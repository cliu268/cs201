// Q2 01 Maze
/*
Description：
There is a n×n maze of characters 0 and 1. If you are in 0, then you can move to one of the four adjacent 
cells with 1 in it. If you are in 1, then you can move to one of the four adjacent cells with 0 in it.  
Given the maze, find out how many cells you can move into (including the original cell).

input：
The first line contains two positive integers n, m.
The next n lines, each line contains n characters (0 or 1, with no space in between)
The next m lines, each contains two positive integers i and j (separated by space), which means the cell in 
the i-th row and the j-th column (the starting point).

output：
m lines，output the answer for each inquiry.

sample input 1：
2 2
01
10
1 1
2 2

sample output 1：
4
4

Note：
For 100% data, n <= 1000, m <= 100000
*/