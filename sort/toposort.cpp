/*
  DFS for toposort.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;
int n, m;
vector<int> adj[MAXN];
bool visited[MAXN], curr[MAXN]; // curr is nodes being currently processed
stack<int> s;

void dfs(int node) {
  visited[node] = curr[node] = true;
  for (int next : adj[node]) {
    if (curr[next]) { // cycle
      cout << "IMPOSSIBLE";
      exit(0);
    }
    else {
      if (!visited[next]) dfs(next);
    }
  }
  s.push(node);
  curr[node] = false; // done processing
}

int main() {
  cin >> n>>m;
  for (int i=0;i<m;i++) {
    int a,b; cin >> a>>b;
    adj[a].push_back(b);
  }

  for (int i=1;i<=n;i++) {
    if (!visited[i]) dfs(i);
  }

  while (s.empty() == false) {
    cout << s.top() << " ";
    s.pop();
  }
}
