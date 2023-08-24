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
#if defined(LUCIFER_SAN)
  freopen("mooin.in", "r", stdin);
  freopen("mooin.out", "w", stdout);
#endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

  //do stuff here
  int n;
  cin >> n;
  vector<int> a;

  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  int i = 0;
  bool right = true;
  while (count(a.begin(), a.end(), 0) != a.size()){
    if (right){
        cout << "R";
        i++;
        a[i] = a[i]-1;
        if (a[i] == 0 || a[i] >= a[i-1]){
            cout << "L";
            i --;
            a[i-1] = a[i-1] -1;
            right = false;
        }
    }
    else{
        cout << "L";
        i++;
        a[i] = a[i]-1;
        if(a[i-1] == 0 || a[i-1] <= a[i]){
            cout << "R";
            i --;
            a[i-1] = a[i-1] -1;
            right = true;
        }
    }
  }

}