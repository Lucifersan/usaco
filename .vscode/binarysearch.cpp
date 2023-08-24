#include <bits/stdc++.h>

using namespace std;


bool f(int x) {
  // Write your own checker here
}

int binarySearchMaximum(int l, int r) {
  while (l < r) {
    int m = l + (r - l + 1) / 2;
    if (f(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  return l;
}

int binarySearchMinimum(int l, int r) {
  while (l < r) {
    int m = l + (r - l) / 2;
    if (f(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

int main() {
  
}