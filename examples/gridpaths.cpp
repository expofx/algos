/*
   Backtracking + pruning to calculate number of paths in nxn grid from upper-left to lower-right corner, which visits each square once

  Optimizations:
   1) first move right OR down, then x2 bc there exist symmetric path reflected across diagonal
   2) if cannot move forward but there are unvisited squares on both sides, terminate
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 7;
ll ways;
bool visited[N+2][N+2] = {{false}}; // add padding to all sides so don't have to check if out of grid (set as visited squares)

void search(int r=1, int c=1, int k=1) {
  if (visited[r][c]) return;

  // optimization 2
  if ((visited[r][c-1] && visited[r][c+1]) && (!visited[r-1][c] && !visited[r+1][c]))
    return;
	if ((visited[r-1][c] && visited[r+1][c]) && (!visited[r][c-1] && !visited[r][c+1]))
    return;

  if (r==N && c==N) {
    if (k==N*N) ways++; // visited all squares
    return;
  }

  visited[r][c] = true;

  search(r+1,c,k+1); // down

  // optimization 1
  if (k!=1) {
    search(r-1,c,k+1); // up
    search(r,c-1,k+1); // left
    search(r,c+1,k+1); // right
  }
  
  visited[r][c] = false;
}

int main() {
  for (int i=0;i<N+2;i++) { // set borders as off grid
    visited[0][i]=true; visited[N+1][i]=true; visited[i][0]=true; visited[i][N+1]=true;
  }

  search();
  cout << ways*2;
}
