#include <iostream>
#include <cstdio>
#include <vector>
#if defined(LUCIFER_SAN)
  #include "a_headerfiles.hpp"
#else 
  #include <bits/stdc++.h>
#endif // defined(LUCIFER_SAN)
 
using namespace std;

int main(void) {
//#if defined(LUCIFER_SAN)
  freopen("lemonade.in", "r", stdin);
  freopen("lemonade.out", "w", stdout);
//#endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

  //do stuff here
  int n;
  cin >> n;
  vector<int> cows;

  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    cows.push_back(temp);
  }

  sort(cows.begin(), cows.end());
  vector<int> cows1;
  for (int i = cows.size()-1; i >= 0; i --)
  cows1.push_back(cows[i]);

  vector<int> line;
  for (int i = 0; i < n; i++){
    if (line.size()<=cows1[i]){
        line.push_back(i);
    }
  }

  cout << line.size() << endl;

}