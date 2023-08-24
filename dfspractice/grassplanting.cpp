#include <iostream>
#include <cstdio>
#include <vector>
#if defined(LUCIFER_SAN)
  #include "a_headerfiles.hpp"
#else 
  #include <bits/stdc++.h>
#endif // defined(LUCIFER_SAN)
 
using namespace std;
const int N = 1e5;
vector<int> num;
vector<int> adjs[N]; // Adjacent edges to each node
bool viss[N];        // Whether node has been visited

// Depth-first-search
void dfs(int a) {

  // If visited, skip
  if (viss[a]) return;

  //If not, do the things
  viss[a] = true;
  num.push_back(adjs[a].size());

  // Visit adjacent nodes
  for (const auto b : adjs[a]) {
    dfs(b);
  }
}

int main(void) {
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);


  // read input
  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    adjs[a - 1].push_back(b - 1);
    adjs[b - 1].push_back(a - 1);

  }

  dfs(0);

  int max = 0;
  for (int i = 0; i < n; i++){
    if (num[i] >= max)
        max = num[i];
  }

  cout << max + 1  << endl;
}