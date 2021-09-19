// Q1 4-peg Hanoi Tower
/*
Tower of Hanoi is a mathematical puzzle. Traditionally, It consists of three poles and a number of disks of 
different sizes which can slide onto any poles. The puzzle starts with the disk in a neat stack in ascending 
order of size in one pole, the smallest at the top thus making a conical shape. The objective of the puzzle 
is to move all the disks from one pole (say ‘source pole’) to another pole (say ‘destination pole’) with the 
help of third and fourth pole (say auxiliary pole).

Input:
How many disks to start with from the source pole.

Output:
Steps to move from source pole to the destination pole.

Sample Input: 3
Output:
Move disk 1 from rod A to rod B
Move disk 2 from rod A to rod C
Move disk 3 from rod A to rod D
Move disk 2 from rod C to rod D
Move disk 1 from rod B to rod D
*/
#include <iostream>
using namespace std;

void hanoi(int n, char source, char peg1, char peg2, char dest) {
    if (n <= 0) return;
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << dest << "\n";
    } else {
        hanoi(n-2, source, peg2, dest, peg1);
        cout << "Move disk " << n-1 << " from rod " << source << " to rod " << peg2 << "\n";
        cout << "Move disk " << n << " from rod " << source << " to rod " << dest << "\n";
        cout << "Move disk " << n-1 << " from rod " << peg2 << " to rod " << dest << "\n";
        hanoi(n-2, peg1, source, peg2, dest);
    }
}

int main(void) {
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C', 'D');
    return 0;
}