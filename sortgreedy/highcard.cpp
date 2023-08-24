#include <iostream>
#include <cstdio>
#include <vector>
#if defined(LUCIFER_SAN)
  #include "a_headerfiles.hpp"
#else 
  #include <bits/stdc++.h>
#endif // defined(LUCIFER_SAN)
 
using namespace std;

bool binarySearch(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main(void) {
  freopen("highcard.in", "r", stdin);
  freopen("highcard.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);

  //do stuff here
  int n;
  cin >> n;
  vector<int> elsie;

  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    elsie.push_back(temp);
  }
  sort(elsie.begin(), elsie.end());
  int bessie = 0;
  int res = 0;
  for (int i = 0; i < elsie.size(); i++){
    while (bessie <= elsie[i]||binarySearch(elsie, bessie)){
      bessie++;
    }
    if (bessie > 2*n) break;
    res++;
    bessie++;
  }

  cout << res << endl;

}