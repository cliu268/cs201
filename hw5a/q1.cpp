// A. Labyrinth and Maze
//https://www.xinyoudui.com/contest?courses=350&books=253&pages=6397&fragments=11614&problemId=1013&pattern=0
// Same question found in hw4 q1.cpp
/*
Description:
The mouse walks the labyrinth, which is a NxN square. The mouse starts from the upper left corner (entrance) to the lower right corner (exit) and 
can move up, down, left or right. The mouse can only visit each cell once. Your task is to find:

1. The number of shortest paths
2. The distance of the shortest path/paths

Input:
The first line is a positive integer n (n<50).
Next n rows is n number (1 or 0)  per row, 0 means passing and 1 means blocking.

Output:
The number of the shortest paths.
The length of shortest path.

Sample input:
5
0 0 0 0 0
0 1 1 1 0
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0

Sample output:
1
9
*/