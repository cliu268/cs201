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
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct f {
    int l, c;
    f(int a, int b) : l(a), c(b) {}
};
queue<f> q;

void exploreNeighbors(f current, vector<int> &k, vector<bool> &v, int &B, bool &found) {
    for (int i = 0; i < 2; i++) {
        f next = f(current.l, current.c+1);
        if (i == 0) { // move down
            next.l -= k[current.l];
        } else { // move up
            next.l += k[current.l];
        }
        if (next.l < 0 || next.l >= k.size() || v[next.l]) {
            continue;
        }
        v[next.l] = true;
        if (next.l == B) {
            cout << next.c << '\n';
            found = true;
            return;
        }
        q.push(next);
    }
}

void bfs(vector<int> &k, vector<bool> &v, int &A, int &B) {
    q.push(f(A, 0));
    v[A] = true;
    bool found = false;
    while (!q.empty()) {
        f current = q.front();
        q.pop();
        if (!found) {
            exploreNeighbors(current, k, v, B, found);
        }
    }
    if (!found) {
        cout << -1 << '\n';
    }
}

int main(void) {
    int N, A, B;
    cin >> N;
    while (N > 0) {
        cin >> A >> B;
        vector<int> k(N);
        vector<bool> v(N, false);
        for (int i = 0; i < N; i++) {
            cin >> k[i];
        }
        if (A == B) {
            cout << 0 << '\n';
        } else {
            A--, B--;
            bfs(k, v, A, B);
        }
        cin >> N;
    }
    return 0;
}

// using namespace std;
 
// vector<int> floors;
// int n,a,b;
// vector<bool> visited;
// struct point {
//   int floor, length;
//   point(int a, int b) : floor(a), length(b) {}
// };
// queue<point> q;
// bool broke=false;
// void exploreNeighbors(int floor, int length) {
//   if (a==b) {
//     cout<<0;
//     broke=true;
//     return;
//   }
//   length++;
//   int newfloor;
//   for (int i=0; i<2; i++) {
//     if (i==0) {
//       newfloor=floor+floors[floor-1];
//     }
//     else {
//       newfloor=floor-floors[floor-1];
//     }
//     if (newfloor<1 || newfloor>floors.size()) {
//       continue;
//     }
//     if (visited[newfloor-1]) {
//       continue;
//     }
//     visited[newfloor-1]=true;
//     if (newfloor==b) {
//       cout<<length;
//       broke=true;
//       return;
//     }
//     q.push(point(newfloor, length));
//   }
// }
// void bfs() {
//   q.push(point(a, 0));
//   while (!q.empty() && !broke) {
//     point curr=q.front();
//     q.pop();
//     exploreNeighbors(curr.floor, curr.length);
//   }
//   if (broke==false) {
//     cout<<-1;
//   }
//   broke=false;
//   for (int i=0; i<visited.size(); i++) {
//     visited[i]=false;
//   }
// }
// int main() {
//   cin>>n;
//   while (n!=0) {
//     cin>>a>>b;
//     for (int i=0; i<n; i++) {
//       int x; cin>>x;
//       floors.push_back(x);
//     }
//     for (int i=0; i<n; i++) {
//       visited.push_back(false);
//     }
//     bfs();
//     cin>>n;
//   }
// }