//#include <iostream>
#if defined(LUCIFER_SAN)
  #include "a_headerfiles.hpp"
#else 
  #include <bits/stdc++.h>
#endif // defined(LUCIFER_SAN)

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
  for (const auto b : adjs[a]) {
    dfs(b);
  }
}

int main() {
#if defined(LUCIFER_SAN)
  freopen("755C.in", "r", stdin);
  freopen("755C.out", "w", stdout);
#endif // defined(LUCIFER_SAN)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Read input
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    adjs[i].push_back(a - 1);
    adjs[a - 1].push_back(i);
  }

  // Traverse
  int count = 0;
  for (int i = 0; i < n; i++){
    if (viss[i]==false) count ++;
    dfs(i);
  }

  cout << count << endl;
}