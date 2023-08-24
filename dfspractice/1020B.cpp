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

vector<int> adjs[N]; // Adjacent edges to each node
bool viss[N];        // Whether node has been visited
int hi;

// Depth-first-search
void dfs(int a) {
  // If visited, skip
  if (viss[a]) {
    hi = a;
    return;
  }
  viss[a] = true;
  
  // Visit adjacent nodes
  for (const auto b : adjs[a]) {
    dfs(b);
    //if (viss[b]) hi = b;
  }
}

int main(void) {
#if defined(LUCIFER_SAN)
  freopen("1020B.in", "r", stdin);
  freopen("1020B.out", "w", stdout);
#endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

// Read input
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    adjs[i].push_back(a - 1);
  }

  // Traverse
  for (int i = 0; i < n; i++){
    dfs(i);
    cout << hi + 1 << " ";
    for (int j = 0; j < n; j++){
        viss[j] = false;
    }
  }
}