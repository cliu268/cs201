// B. Where to Travel
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6573&fragments=11889&problemId=9186&pattern=0
/*
To make this decision, you are given a map of size NxN with '@' marking your location on the map. The map comprises various characters, 
where 'M' represents the mountains, 'B' represents the beach, and 'X' represents an obstacle that can't be crossed. You can move in the 
north, south, east, or west direction from any point on the map, but you must not go off the map or hit a roadblock.

To reach either the beach or the mountains, you can pass through the mountains to get to the beach and vice versa. You don't need to worry 
as there will be a possible path to either the beach or the mountains or both. Your task is to determine the best decision – either "Beach," 
"Mountains," or "Either" (if the distances are the same) – along with the shortest path to your destination.

Input:
The input consists of the size of the map N on the first line, followed by N lines with N space-separated characters representing each 
character in the map.

Output:
The output includes two space-separated values. The first value is a string representing your decision, and the second value is the shortest 
path length to reach your destination.

Sample Input:
5
. @ X . .
. . X . .
X . . X B
M . . . .
. . . . .

Sample Output:
Mountains 4

Explanation: In this example the cost to go to the mountains takes 4 steps, while the cost to go to the beach takes 7 steps. 
Note: 2≤N≤5
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> maze;
int ans=0, temp=0;
int n;
int x,y, mx, my, bx, by;
int pm=0, pb=0;

void floodfill(int sx, int sy){

    if (sx<0 || sx>=n || sy<0 || sy>=n){
        return;
    }
    
    if (maze[sx][sy] == 1 || maze[sx][sy] == -1){
        return;
    }

    if(sx==mx && sy==my){
        if(pm!=0){
            pm=min(pm, temp);
        }
        else{
            pm=temp;
        }
    }

    if(sx==bx && sy==by){
        if(pb!=0){
            pb=min(pb, temp);
        }
        else{
            pb=temp;
        }
    }

    temp++;
    maze[sx][sy] = -1;

    floodfill(sx-1, sy);
    floodfill(sx+1, sy);
    floodfill(sx, sy-1);
    floodfill(sx, sy+1);

    maze[sx][sy] = 0;
    temp--;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        vector<int> row(n);
        for(int j=0; j<n; j++){
            char input;
            cin >> input;
            if (input == ' ') {
                cin >> input;
            }

            if(input=='X'){
                row[j]=1;
            }
            else if(input=='.'){
                row[j]=0;
            }
            else if(input=='@'){
                x=i;
                y=j;
                row[j]=0;
            }
            else if(input=='B'){
                bx=i;
                by=j;
                row[j]=0;
            }
            else if(input=='M'){
                mx=i;
                my=j;
                row[j]=0;
            }
        }
        maze.push_back(row);
    }

    floodfill(x, y);

    if(pb==pm){
        cout << "Either" << " " << pm << endl;
    }
    else if((pb > pm && pm != 0) || pb == 0){
        cout << "Mountains" << " " << pm << endl;
    }
    else if((pm > pb && pb != 0) || pm == 0){
        cout << "Beach" << " " << pb << endl;
    }
}