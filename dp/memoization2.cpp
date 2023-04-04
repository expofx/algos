// using iterative method instead of recursion

#include <iostream>
#include <vector>
using namespace std;

#define INF 2e9

int main() {
  int n,x; cin >> n>>x;
  vector<int> coins(n), value(x+1);
  for (int i=0; i<n; i++) cin >> coins[i];
  
  value[0]=0;
  for (int i=1;i<=x;i++) {
    value[i]=INF;
    for (int c:coins) {
      if (i-c>=0) value[i]=min(value[i],value[i-c]+1);
    }
  }

  cout << (value[x]==INF ? -1 : value[x]);
}
