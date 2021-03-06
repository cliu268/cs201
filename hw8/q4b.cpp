// Bonus Q4 Why Did the Cow Cross the Road
// USACO 2017 February Contest, Bronze
// Problem 1. Why Did the Cow Cross the Road
// http://www.usaco.org/index.php?page=viewproblem2&cpid=711
/*
While the age-old question of why chickens cross roads has been addressed in great depth by the scientific community, 
surprisingly little has been published in the research literature on the related subject of cow crossings. Farmer John, 
well-aware of the importance of this issue, is thrilled when he is contacted by a local university asking for his assistance 
in conducting a scientific study of why cows cross roads. He eagerly volunteers to help.

As part of the study, Farmer John has been asked to document the number of times each of his cows crosses the road. He 
carefully logs data about his cows' locations, making a series of N observations over the course of a single day. Each 
observation records the ID number of a cow (an integer in the range 1…10, since Farmer John has 10 cows), as well as 
which side of the road the cow is on.

Based on the data recorded by Farmer John, please help him count the total number of confirmed crossings. A confirmed 
crossing occurs when a consecutive sightings of a cow place it on different sides of the road.

INPUT FORMAT (file crossroad.in):
The first line of input contains the number of observations, N, a positive integer at most 100. Each of the next N lines 
contains one observation, and consists of a cow ID number followed by its position indicated by either zero or one (zero for 
one side of the road, one for the other side).

OUTPUT FORMAT (file crossroad.out):
Please compute the total number of confirmed crossings.

SAMPLE INPUT:
8
3 1
3 0
6 0
2 1
4 1
3 0
4 0
3 1

SAMPLE OUTPUT:
3
In this example, cow 3 crosses twice -- she first appears on side 1, then later appears on side 0, and then later still 
appears back on side 1. Cow 4 definitely crosses once. Cows 2 and 6 do not appear to cross.
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);    

    int n, cow[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    cin >> n;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int id, side;
        cin >> id >> side;
        if (cow[id-1] != -1 && cow[id-1] != side) {
            answer++;
        }
        cow[id-1] = side;
    }
    cout << answer;
    return 0;
}