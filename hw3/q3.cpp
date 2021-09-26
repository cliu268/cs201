// Q3 Floodfill
/*
Count how many cells can be reached within a N by N maze, with a start point, and with the rule that each 
step you can move up, down, top-left, bottom-right for one step. 

Input format:
Three integers in the first line, representing N, and location of start point.
Next N lines: each line has N 0/1 separated by space, where 0 represents the position you may fill, and 1 
represents the barrier. (1<=N<=500)

Output format:
Single integer representing number of cells you can reach.

Sample input:
3 0 0
0 0 0
0 1 0
1 0 1

Sample output:
3
*/