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
const int MAX = 1e9;

vector<int> adjs[N]; 
bool viss[N];     
set<int> members[N]; // Members of each component
int roots[N]; // Root of each node's component
pair<int, int> distances[N]; // Distances from each component to 1 and N, respectively

// Depth-first-search
void dfs(int a, int root) {
  // If visited, skip
  if (viss[a]) return;
  viss[a] = true;

  // Add node to connected component
  members[root].insert(a);
  
  // Visit adjacent nodes
  for (auto b : adjs[a]) {
    dfs(b, root);
  }
}

int findNearestValueInSet(const set<int>& haystack, int needle) {
    // Pair can be used to store the optimal result and the coresponding
    // value used to get there
    pair<int, int> result (MAX, -1);
    // Find the smallest value greater than "needle" in "haystack",
    // then go down one, if possible
    auto findingLesser = haystack.upper_bound(needle);
    if (findingLesser != haystack.begin()) {
        int value = *prev(findingLesser);
        result = min(result, pair<int, int>(abs(value - needle), value));
    }
    // Find the smallest value greater than or equal to "needle" in "haystack"
    auto findingGreater = haystack.lower_bound(needle);
    if (findingGreater != haystack.end()) {
        int value = *findingGreater;
        result = min(result, pair<int, int>(abs(value - needle), value));
    }
    // Return the value
    return result.second;
}

int main() {
  #if defined(LUCIFER_SAN)
  freopen("barnconnect.in", "r", stdin);
  freopen("barnconnect.out", "w", stdout);
  #endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin>> t;
  
  for ( int j = 0; j < t; j++){

    int n, m;
    cin >> n >> m;

    // Reset before starting
    for (int i = 0; i < n; i++) {
        adjs[i].clear();
        members[i].clear();
    }
    fill_n(viss, n, false);
    fill_n(distances, n, pair<int, int>(MAX, MAX));
  
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjs[a - 1].push_back(b - 1);
        adjs[b - 1].push_back(a - 1);
    }
    
    // Visit all connected components
    if (!viss[0]) dfs(0, 0);
    if (!viss[n - 1]) dfs(n - 1, n - 1);
    for (int i = 0; i < n; i++) {
        if (!viss[i]) dfs(i, i);
    }
    
    // Find minimum distance of each component to 1's component
    // and N's component, respectively
    for (int i = 0; i < n; i++) {
        int distanceTo1 = findNearestValueInSet(members[0], i);
        int distanceToN = findNearestValueInSet(members[n - 1], i);
        int root = roots[i];
        distances[root].first = min(distances[root].first, distanceTo1);
        distances[root].second = min(distances[root].second, distanceToN);
    }

    // For each component, check if it can be used optimally
    // to find a path between 1 and N
    int result = MAX;
    for (int i = 0; i < n; i++) {
        int root = roots[i];
        result = min(result, distances[root].first + distances[root].second);
    }

    cout << result << endl;
  }

}