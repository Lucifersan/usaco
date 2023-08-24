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

vector<int> adjs[N]; 
bool viss[N];     
bool closed[N];   

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

int main(void) {
//#if defined(LUCIFER_SAN)
  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);
//#endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    adjs[a - 1].push_back(b - 1);
    adjs[b - 1].push_back(a - 1);
  }

  bool temp = true;
  dfs(0);
  //check if every single barn has been visited
  for (int j = 0; j < n; j++){
    if (viss[j] == false) temp = false;
  }
  if (temp == false) cout << "NO" << endl;
  else cout << "YES" << endl;
  for (int j = 0; j < n; j++){
        viss[j] = false;
  }

  // Traverse
  for (int i = 0; i < n-1; i++){
    int closing;
    cin >> closing;
    closed[closing-1]=true;
    adjs[closing-1].clear();

    vector<int> open;
    for (int i = 0; i < n; i++){
      if(!closed[i]) open.push_back(i);
    }

    dfs(open[0]);
    temp = true;
    //check if every single barn has been visited
    for (int j = 0; j < n; j++){
        if (viss[j] == false && !closed[j]) temp = false;
    }
    if (temp == false) cout << "NO" << endl;
    else cout << "YES" << endl;

    //reset
    for (int j = 0; j < n; j++){
        viss[j] = false;
    }
    }


}