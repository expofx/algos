/*
  Using backtracking and generating permutations to solve N queens problem.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 8;
lli ways;
bool col[30], ldiag[30], rdiag[30] {false}; // don't have to assign rows bc we are assuming each are placed in different rows

void search(lli r) {
  if (r==N) { // reached end of search and found a way
    ways++;
    return;
  }
  
  for (lli c=0; c<N; c++) {
    // if the queen can't be placed, stop searching
    if (col[c] || ldiag[r+c] || rdiag[r-c+7]) {
      continue;
    }
    col[c] = ldiag[r+c] = rdiag[r-c+7] = true;
    search(r+1); // next row
    col[c] = ldiag[r+c] = rdiag[r-c+7] = false; // backtrack
  }
}

int main() {
  search(0);
  cout << ways << "\n";
}

