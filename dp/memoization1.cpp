/*
  Using memoization/recursion to solve the coin change problem.
*/
#include <iostream>
#include <vector>
using namespace std;

#define INF 2e9

vector<int> value, coins;
vector<bool> seen;

int solve(int x) {
  if (x==0) return 0;
  if (x<0) return INF;
  if (seen[x]) return value[x];

  int best=INF;
  for (int c:coins) {
    best = min(solve(x-c)+1, best);
  }
  value[x] = best; seen[x] = true;
  return best;
}

int main() {
  int n,x; cin >>n>>x;
  value.resize(x+1); seen.resize(x+1); coins.resize(n);
  for (int i=0;i<n;i++) cin >> coins[i];

  int ans = solve(x);
  cout << (ans==INF ? -1 : ans);
}

