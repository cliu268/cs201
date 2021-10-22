// Q5 Matrix with Treasures I
/* 
Time limit：1s   
Space limit: 128M
Description：
Explorers in the country of X recently discovered some ruins. It is like a matrix but it has a lot of treasures.

Explorers figured out the map of this matrix using an "Eagle Eyes" detector. This is a 2D map. '#' means a trap 
which by no means can be gone through. '*' means an accesible spot. Some spots have treasures there, whose value 
is indicated by a number. 

The unique thing about this matrix is that once you pass a spot that spot will disappear. So basically you can not 
reach the same spot again.

The explorers wanted to know how many treasures they can get by maximum if they enter from lower left entrance and 
exit from lower right exit.

Input：
1st line has two integers n and m to describe the matrix size.
Then there will be n lines, each line has m characters. These lines/row describe the map. 
Make sure you do not have a trap on the extrance. 

Output：
One integer number, which is the max value the explorer can obtain. 
if you cannot get to the exit, output -1.

Sample Input：
5 6 
1****# 
*###2# 
4###*# 
*###1# 
**1***

Sample Output ：
6

Notes：
1 <= N，M<= 7，0<=each treasure<=9
*/