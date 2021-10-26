// Q2 I am Autistic
/*
Time：0.2 
Space：32M

Description：
You will become autistic if you fall into the sea of excrescence. But Boy Ma won't.
Boy Ma gives you a map of the Sea of Excrescence. It has n rows (from 1 to n) and m columns (from 1 to n). Two spots are 
connected if they are neighbors. An example: (x,y) is connected to (x,y), (x-1,y), (x+1,y), (x,y-1) and (x,y+1) only. 

Every spot could have an excrescence (spot has a value of 1) or not (value=0). 
Let's define the so-called Excrescence Block. A Excrescence Block is an area where any two spots of excrescence can be 
reached each other through neighbors.

Now please find out how many spots with excrescence can a biggest Excrescence Block have.
You may need to refer to the samples for better understanding of the questions.

Input：
The first line has two numbers n and m.
Then there are n lines, each line has m numbers. Those numbers are either 1 or zero.

Output：
One number.

Sample Input1：
5 4
0101
0111
1000
1100
0101

Sample Output1：
5

Notes：
1<=n, m<=50
*/