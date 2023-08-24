#include <iostream>

using namespace std;

const int N = 1e5;

vector<int> adjs[N]; // Adjacent edges to each node
bool viss[N];        // Whether node has been visited

// Depth-first-search
void dfs(int a) {
  // If visited, skip
  if (viss[a]) return;
  viss[a] = true;
  
  // Visit adjacent nodes
  for (auto b : adjs[a]) {
    dfs(b);
  }
}

int main() {
  // Read input, n = # of nodes, m = # of edges
  int n, m;
  cin >> n >> m;
  // Read edges
  for (int i = 0; i < m; i++) {
    // Bi-directional edges; a <-> b
    int a, b;
    cin >> a >> b;
    adjs[a - 1].push_back(b - 1);
    adjs[b - 1].push_back(a - 1);
    // Directed edges; a -> b
    // int a, b;
    // cin >> a >> b;
    // adjs[a - 1].push_back(b - 1);
  }
  // Traverse
  dfs(0);
}