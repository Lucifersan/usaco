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
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);
#endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

  //do stuff here
}