/*
  Iterative method of solving the knapsack problem, given n items each with a weight and value
  -goal is to maximize the total value of the items with given capacity W
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n,x; cin >> n>>x; // x is weight capacity W
  vector<int> weight(n), value(n);

  for (int i=0;i<n;i++) cin >> weight[i];
  for (int i=0;i<n;i++) cin >> value[i];

  vector<int> dp(x+1,0);
  for (int i=0;i<n;i++) {
    for (int j=x;j>=weight[i];j--) {
      dp[j]=max(dp[j], value[i]+dp[j-weight[i]]);
    }
  }

  cout << dp[x];
}
