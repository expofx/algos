/*
  Dijkstra's algorithm for shortest path in weighted graph.
  
  - Start off with distances INF besides root node
  - At each step, select unprocessed node with smallest distance (priority queue)
    - Go through adj edges and reduce nodes
  - Repeat until all nodes are processed

  Better than bellman ford because it checks fewer nodes (greater weight nodes may not be checked in order to process all nodes)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5;
bool processed[MAXN];
vector<pair<int,int>> adj[MAXN]; // adj[a] = (b,w) edge to node b with weight w
priority_queue<pair<ll,int>> pq; // {-dist,b}
int n,m;
ll dist[MAXN];

// dijkstra's
void dijkstra(int s) {
  for (int i=0; i<n; i++) dist[i] = LLONG_MAX;
  dist[s] = 0;
  pq.push({0,s});

  while (!pq.empty()) {
    int a = pq.top().second; pq.pop(); // get node w shortest dist
    if (processed[a]) continue;
    processed[a] = true;

    for (auto u : adj[a]) {
      int b = u.first; ll w = u.second;
      if (dist[a]+w < dist[b]) {
        dist[b] = dist[a]+w;
        pq.push({-dist[b],b});
      }
    }
  }
}

int main() {
  cin >> n>>m;
  for (int i=0; i<m; i++) {
    int a,b,c; cin >> a>>b>>c;
    adj[a-1].push_back({b-1,c});
  }

  dijkstra(0);
  for (int i=0; i<n; i++) cout << dist[i] << " ";
}

