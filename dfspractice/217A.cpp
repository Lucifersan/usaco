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

vector<int> coord[N];
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
    //if (viss[b]) hi = b;
  }
}

int main(void) {
#if defined(LUCIFER_SAN)
  freopen("217A.in", "r", stdin);
  freopen("217A.out", "w", stdout);
#endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

// Read input
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a;
    cin >> b;
    coord[i].push_back(a);
    coord[i].push_back(b);
  }

  //Create tree
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++){
        if(coord[i][0] == coord[j][0] && i != j){
            adjs[i].push_back(j);
            adjs[j].push_back(i);
        }
        if(coord[i][1] == coord[j][1] && i != j){
            adjs[i].push_back(j);
            adjs[j].push_back(i);
        }
    }
  }


  // Traverse
  int count = 0;
  for (int i = 0; i < n; i++){
    if (viss[i]==false) count ++;
    dfs(i);
  }

  cout << count - 1 << endl;
}