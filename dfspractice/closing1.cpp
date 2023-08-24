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

bool isIn(int a, vector<int> closed){
    for (int j = 0; j < closed.size(); j++){
        if (a == closed[j]) return true;
    }
    return false;
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

  dfs(0);
  bool temp = true;
  //check if every single barn has been visited
  for (int j = 0; j < n; j++){
    if (viss[j] == false) temp = false;
  }
  if (temp == false) cout << "NO" << endl;
  else cout << "YES" << endl;

  for (int j = 0; j < n; j++){
    viss[j] = false;
  }

  vector<int> closed;


  // Traverse
  for (int i = 0; i < n-1; i++){
    int closing;
    cin >> closing;
    adjs[closing-1].clear();
    closed.push_back(closing-1);

    vector<int> open;
    for (int i = 0; i < n; i++){
      if(!isIn(i, closed)) open.push_back(i);
    }

    temp = true;
    dfs(open[0]);
    //check if every single barn has been visited
    for (int j = 0; j < n; j++){
        if (viss[j] == false && !(adjs[j].size()==0)) temp = false;
    }
    if (temp == false) cout << "NO" << endl;
    else cout << "YES" << endl;

    //reset
    bool viss[N];
  }
}