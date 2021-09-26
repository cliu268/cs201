// Q4 Labyrinth
/*
A mouse walks the labyrinth that is a N by N square. The mouse enters through the upper left corner (0,0) 
and exits from the lower right corner (N, N). It is not allowed to go back. Find out the length of the 
shortest path and the number of the shortest path (N<15)

Input:
The first line is a positive integer n
The following n rows has n numbers per row containing 1 or 0. 0 can pass, 1 can not

Output:
The number of the shortest path
Shortest path length

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

time limit: 1000,  memory limit: 65536
*/