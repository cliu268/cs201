/* Q1 Social Circle
Problem Statement
There are n students in class. Some of them are friends, and some of them are not. Friendship has 
transitivity. For example, if A is B's friend, and B is C's friend, and A will be C's friend as a result of 
transitivity. So-called social circle, means a set of people who are all friends to each other. 
Note that there could be multiple social circles.

Given a n by n matrix M, representing the friendships in class. If M[i][j] = 1, i-th student and j-th student 
are friends to each other; otherwise their relationship is unknown (with transitivity students could be 
friends even they are not friends directly). Please compute the number of social circles in total.

Input Format
The first line is n.
Over the next n lines, we will have n integer each line, and each integer is 1 or 0.

Output Format
One integer representing total number of social circles.

Sample Input：
3
1 1 0
1 1 1
0 1 1

Sample Output：
1

Limitation:
1<=n<=200
*/