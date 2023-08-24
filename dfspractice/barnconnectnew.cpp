#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const long long MAX = 1e18;

vector<int> adjs[N];
bool visited[N];
int roots[N];
set<int> members[N];
pair<long long, long long> distances[N];

void dfs(int a, int root) {
  if (visited[a]) return;
  visited[a] = true;
  
  roots[a] = root;
  members[root].insert(a);
  
  for (auto b : adjs[a]) dfs(b, root);
}

long long findDistance(set<int>& haystack, int needle) {
  long long result = MAX;
  auto lessEqual = haystack.upper_bound(needle);
  if (lessEqual != haystack.begin()) {
    int value = *prev(lessEqual);
    result = min(result, (long long) (needle - value) * (needle - value));
  }
  auto greaterEqual = haystack.lower_bound(needle);
  if (greaterEqual != haystack.end()) {
    int value = *greaterEqual;
    result = min(result, (long long) (needle - value) * (needle - value));
  }
  return result;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int t;
  cin >> t;
  
  while (t--) {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
      members[i].clear();
      adjs[i].clear();
    }
    
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      
      adjs[a - 1].push_back(b - 1);
      adjs[b - 1].push_back(a - 1);
    }
    
    fill_n(visited, n, false);
    dfs(0, 0);
    dfs(n - 1, n - 1);
    for (int i = 0; i < n; i++) dfs(i, i);
    
    if (roots[0] == roots[n - 1]) {
      cout << 0 << endl;
      continue;
    }
    
    fill_n(distances, n, pair<long long, long long>{MAX, MAX});
    for (int i = 0; i < n; i++) {
      long long distance1 = findDistance(members[0], i);
      long long distanceN = findDistance(members[n - 1], i);
      
      int root = roots[i];
      distances[root].first = min(distances[root].first, distance1);
      distances[root].second = min(distances[root].second, distanceN);
    }
    
    long long result = MAX;
    for (int i = 0; i < n; i++) if (roots[i] == i) {
      auto [distance1, distanceN] = distances[i];
      result = min(result, distance1 + distanceN);
    }
    
    cout << result << endl;
  }
}
```