/*
  Bellman-Ford algorithm for graphs with negative distance.

  - Each time, we go through all the edges and see if we can minimize the distances
  - We do this n-1 times because we want to check the paths of length 1..n-1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5;

int n,m,a,b,w;
vector<tuple<int,int,int>> edges; // edge (a,b,w) from node a to b with weight w
ll dist[MAXN];

// bellman-ford
void bf(int s) {
  for (int i=0; i<n; i++) dist[i] = LLONG_MAX;
  dist[s] = 0;
  
  for (int i=0; i<n-1; i++) {
    for (auto e : edges) {
      tie(a,b,w) = e;
      dist[b] = min(dist[b], dist[a]+w);
    }
  }
}

int main() {
  cin >> n>>m;
  for (int i=0; i<m; i++) {
    cin >> a>>b>>w;
    edges.push_back({a-1,b-1,w}); // nodes are 1-indexed
  }

  bf(0);
  for (int i=0; i<n; i++) cout << dist[i] << " ";
}

