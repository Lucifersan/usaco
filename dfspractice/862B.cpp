#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
vector<int> colored;      // list of colored nodes
vector<int> adjs[100000]; // adjacent nodes for each node
bool visited[100000];     // whether node is visited

void dfs(int u, bool color) {
  // if the node is colored, add it to the list of colored nodes
  if (color)
    colored.push_back(u);

  // mark current node as visited
  visited[u] = true;

  // visit unvisited neighbors
  for (const auto v : adjs[u])
    if (!visited[v])
      dfs(v, !color); // switch colors, since no two nodes of the
                      // same color may touch. this is guaranteed
                      // to produce a bipartite graph because it's
                      // a tree; just think about it visually, draw
                      // it if you have to
}
 
int main(void) {
#if defined(LUCIFER_SAN)
  freopen("bipartiteness.in", "r", stdin);
  freopen("bipartiteness.out", "w", stdin);
#endif // defined(LUCIFER_SAN)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // read input
  int n;
  cin >> n;
  for (int o = n; --o;) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adjs[u].push_back(v);
    adjs[v].push_back(u);
  }

  dfs(0, 0);

  // `count` stores the result
  long long int count = 0;
  
  // using combinatorics, any uncolored nodes can be paired
  // with every colored node. however, already paired nodes
  // can't be re-paired. we know that all neighbors of
  // colored nodes are uncolored so we just subtract them
  // from the uncolored total to simulate avoiding duplicates
  int uncolored = n - colored.size();
  for (auto u : colored)
    count += uncolored - adjs[u].size();

  // print result
  printf("%lli\n",count);
  return 0;
}