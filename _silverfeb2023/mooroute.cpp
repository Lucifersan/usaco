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

// Depth-first-search
void dfs(int a)
{
    // If visited, skip
    if (viss[a])
        return;
    viss[a] = true;

    // Visit adjacent nodes
    for (auto b : adjs[a])
    {
        dfs(b);
    }
}

bool checkConnected(const vector<int> &flight1, const vector<int> &flight2, int grace){
    
}

int main(void) {
#if defined(LUCIFER_SAN)
  freopen("mooroute.in", "r", stdin);
  freopen("mooroute.out", "w", stdout);
#endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

  //do stuff here
  int n, m;
  cin >> n >> m;

  vector<int> flights[m];
  for (int i = 0; i < m; i++){
    int c,r,d,s;
    cin >> c >> r >> d >> s;
    flights[i].push_back(c);
    flights[i].push_back(r);
    flights[i].push_back(d);
    flights[i].push_back(s);
  }

  vector<int> airports;
  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    airports.push_back(temp);
  }




    // Read edges
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (checkConnected(cows[i], cows[j]) && i != j){
                adjs[i].push_back(j);
            }
        }
    }
    // Traverse
    int max, count;
    max = 0;
    count = 0;
    for (int i = 0; i < n; i++)
    {
        dfs(i);
        for (int j = 0; j < n; j++){
            if (viss[j]) count++;
        }
        if (count > max) max = count;
        count = 0;
        for (int i = 0; i < n; i++){
            viss[i] = false;
        }
    }

    cout << max << endl;
}


}