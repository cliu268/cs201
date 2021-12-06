// Q2 UP and DOWN
/*
Time limit：1s   memory limit：128M

Description：
There is a strange elevator. It can stop at every floor and every floor has a Ki（0 <= Ki <= N) . The elevator has only 
two buttons: up and down. When you are in floor i and press "UP", you will go up Ki floors and reach the  i+Ki floor. 
If you press "DOWN", you will go down Ki floors and reach the i-Ki floor. For example, in a five-floor building, k1 = 3，
k2 = 3，k3 = 1，k4 = 2，k5 = 5. On floor 1, if you press "UP", you will reach the 4-th floor. If you press "DOWN", the 
elevator cannot do this task, because there is no -2 floor.
Based on those information, please solve this problem: when you are on floor A and want to go to floor B, at least how 
many times do you have to press the "UP" or "DOWN " buttons?

Input：
The first line contains three integers N，A，B（1 <= N，A，B <= 200）
The second line contains N integers k1，k2，...... kn
a single 0 means the end of input

Output：
Output the least time you press the buttons. If it can not be achieved, print -1.

Sample input 1：
5 1 5
3 3 1 2 5
0

Sample output 1：
3
*/