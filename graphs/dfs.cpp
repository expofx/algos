/*
  Recursive implementation of DFS
*/

#include <vector>
#include <iostream>
using namespace std;

const int N = 1e5+1; // define max nodes
vector<int> adj[N]; // adj list is array of vectors
bool visited[N];

void dfs(int node) {
  cout << node << " ";
  visited[node] = true;
  for (int next : adj[node]) {
    if (!visited[next]) dfs(next);
  }
}

int main() {
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(3);

  dfs(2); // start from node 2
}
