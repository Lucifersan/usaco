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
  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);
//#endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

  //get n, q, cow breeds
  int n, q;
  cin >> n;
  cin >> q;

  int cows[n];
  for (int i = 0; i < n; i++){
    cin >> cows[i];
  }

  //make prefix sum list
  vector<vector<int> > sums;
  int h, g, j;
  h = 0;
  g = 0;
  j = 0;
  for (int i = 0; i < n; i++){
    if ( cows[i] == 1) h++;
    else if (cows [i] == 2) g++;
    else j++;

    vector<int> temp;
    temp.push_back(h);
    temp.push_back(g);
    temp.push_back(j);
    sums.push_back(temp);
  }

  //return results for each query
  for (int i = 0; i < q; i++){
    //get query
    int start, end;
    cin >> start >> end;

    if (start == 1){
        cout << sums[end-1][0] << " ";
        cout << sums[end-1][1] << " ";
        cout << sums[end-1][2] << endl;
    }

    else{
        cout << sums[end-1][0]-sums[start-2][0]  << " ";
        cout << sums[end-1][1]-sums[start-2][1] << " ";
        cout << sums[end-1][2]-sums[start-2][2] << endl;
    }
  }
}