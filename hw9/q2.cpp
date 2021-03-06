// Q2 Catch the Cow
/*
Title description:
Farmer John has been informed of the location of the escaped cow and hopes to catch her immediately. He starts at 
point N (0≤N≤100,000) on the number line, and the cow is at point K (0≤K≤100,000) on the same number line. Farmer 
John has two modes of transportation: walking and teleportation.

*Walking: FJ can move from any point X to X-1 or X+1 point in one minute
*Transport: FJ can move from any point X to point 2*X in one minute.
If the cow doesn't know its pursuit and doesn't move at all, how long will it take for Farmer John to retrieve it?

Input format:
Line 1: Two integers separated by spaces: N and K.

Output format:
Line 1: The minimum time (in minutes) required for Farmer John to catch a fugitive cow.

Sample input:
5 17

Sample output:
4

Hint
Solution for sample data is: 5-10-9-18-17, thus it needs 4 minutes
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> visited(100001, 0);

int main(void) {
    int n, k;
    cin >> n >> k;
    if (n >= k) {
        cout << n-k;
    } else { // n < k lets do bfs
        int answer = 0;
        // while (k - n >= n) {
        //     n *= 2;
        //     answer++;
        // }
        queue<pair<int, int>> q;
        visited[n] = 1;
        q.push(pair<int, int>(n, 0));
        while (!q.empty()) {
            n = q.front().first;
            answer = q.front().second;
            q.pop();
            if (n == k) {
                cout << answer;
                return 0;
            }
            int next[3] = {1, -1, n};
            answer++;
            for (int i = 0; i < 3; i++) {
                int nn = n + next[i];
                if (nn < 0 || nn > 100000 || visited[nn]) continue;
                if (nn == k) {
                    cout << answer;
                    return 0;
                }
                visited[nn] = 1;
                q.push(pair<int, int>(nn, answer));
            }
        }
    }
    return 0;
}