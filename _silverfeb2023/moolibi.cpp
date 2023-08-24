#include <iostream>
#include <cstdio>
#include <vector>
#if defined(LUCIFER_SAN)
  #include "a_headerfiles.hpp"
#else 
  #include <bits/stdc++.h>
#endif // defined(LUCIFER_SAN)
 
using namespace std;

bool compareVectors(const vector<int>& a, const vector<int>& b) {
    return a.back() < b.back();
}

int distance(const vector<int>& loc, const vector<int>& cow){
    return abs(loc[0]-cow[0]) + abs(loc[1]-cow[1]);
}

bool innocent(const vector< vector<int> >& grazed, const vector<int>& cow, int g){
    bool res = true;
    for (int i = 0; i < g; i++){
        if(distance(grazed[i], cow) > abs(cow[2]-grazed[i][2]) && cow[2] < grazed[i][2]) res = false;
    }
    return res;
}

int main(void) {
#if defined(LUCIFER_SAN)
  freopen("moolibi.in", "r", stdin);
  freopen("moolibi.out", "w", stdout);
#endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

  int g, n;
  cin >> g >> n;

  vector< vector<int> > grazed;
  for (int i = 0; i < g; i++){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> temp;
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);
    grazed.push_back(temp);
  }
  sort(grazed.begin(), grazed.end(), compareVectors);

  int count = 0;
  for (int i = 0; i < n; i++){
    vector<int> cow;
    int a, b, c; 
    cin >> a >> b >> c;
    cow.push_back(a);
    cow.push_back(b);
    cow.push_back(c);

    if (!innocent(grazed, cow, g)) count ++;
  }
  cout << count;
  
}