/*
  Implementation of BFS using queues.
*/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int N = 1e5+1; // define max nodes
vector<int> adj[N]; // adj list is array of vectors
bool visited[N];
queue<int> q;

void bfs(int node) {
  visited[node]=true;
  q.push(node);

  while (!q.empty()) {
    node = q.front(); q.pop(); // process node
    cout << node << " ";

    for (int next : adj[node]) {
      if (!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }
}

int main() {
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(3);

  bfs(2); // start fro node 2
}

