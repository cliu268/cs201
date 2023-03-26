// C. hoof, cloth, scissors
// https://www.xinyoudui.com/contest?courses=350&books=253&pages=6569&fragments=11887&problemId=8022&pattern=0
/*
Description：
You've probably heard of the "rock, paper, scissors" game. FJ's cows like to play a similar game they call "hoof, cloth, scissors" ("hoof" is "rock", 
"cloth" is "paper").

The rules of the game are simple: both sides of the game count to 3 at the same time, and then make a handsign at the same time, representing "hoof", 
"scissors" or "cloth". "Hoof" beats "scissors", "scissors" beats "cloth", and "cloth" beats "hoof". For example, if the first cow gives a "hoof" and 
the second cow gives a "cloth", the second cow wins. Of course, a "draw" is also possible (if the two cows have the same handsigns).

FJ wants to play against his winning cow, Bessie. Bessie, as an expert, is able to predict FJ's handsigns. Unfortunately, as a cow, Bessie is also very 
lazy. In fact, she is only willing to change her handsign up to a fixed number of times to complete the game. For example, she may only want to change 
once, then he may "hoof" a few times and "cloth" the rest.
Given that Bessie can predict the handsigns FJ will make, and the maximum number of times she wants to change her handsign, find the maximum number of 
games she can win.

Input:
The first row contains two numbers: n and k
n: the next n lines each contain the handsign of FJ, either H or P or S (P is paper/cloth)
k: k represents the maximum number of times Bessie wants to change her handsign.

Output:
A number indicates the answer.

Sample input 1:
5 1
P
P
H
P
S

Sample output 1:
4

Note:
1<=n<=100000, 0<=k<=20
*/
// Same question as in cs300 hw2 q1.cpp 
// https://github.com/cliu268/cs300/blob/cb0507c32562bf0ea2e658e04b69ca7d20591062/hw2/q1.cpp (not yet implemented)
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; cin >> n;
  char letters[n+1];
  int paper[n+1]; int scissor[n+1]; int hoof[n+1];
  paper[0]=0; scissor[0]=0; hoof[0]=0;
  for (int i=1; i<=n; i++) {
    cin>>letters[i];
    paper[i]=paper[i-1]; scissor[i]=scissor[i-1]; hoof[i]=hoof[i-1];
    if (letters[i]=='P') {
      paper[i]++;
    }
    if (letters[i]=='H') {
      hoof[i]++;
    }
    if (letters[i]=='S') {
      scissor[i]++;
    }
  }
  int ans=max(paper[n], max(scissor[n], hoof[n]));
  for (int i=1; i<=n; i++) {
    ans=max(ans, paper[i]+hoof[n]-hoof[i]);
    ans=max(ans, paper[i]+scissor[n]-scissor[i]);
    ans=max(ans, hoof[i]+ paper[n]-paper[i]);
    ans=max(ans, hoof[i]+ scissor[n]-scissor[i]);
    ans=max(ans, scissor[i]+paper[n]-paper[i]);
    ans=max(ans, scissor[i]+hoof[n]-hoof[i]);
  }
  cout<<ans;
}