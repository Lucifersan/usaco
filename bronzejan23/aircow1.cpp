#include <bits/stdc++.h>
//#include "a_headerfiles.hpp"
using namespace std;

bool works(int arr[100]){
  for (int i = 0; i < 100; i++) if (arr[i]>=1) return false;
  return true;
}

bool check(const vector<int> vec, int stalls[100], const int initial[], const int final[], const int cools[]){
  for (int i = 0; i < vec.size(); i++){
    for (int j = initial[vec[i]]-1; j < final[vec[i]]; j++){
      stalls[j] -= cools[vec[i]];
    }
  }
  if (works(stalls)) return true;
  else return false;

}

int main(){
  //input
  /*freopen("aircow1.in", "r", stdin);  
  freopen("aircow1.out", "w", stdout); */

  int n, m;
  cin >> n;
  cin >> m;

  int stalls[100];
  for (int i = 0; i < 100; i++) stalls[i] = 0;

  for (int i = 0; i < n; i++){
    int temp, s, t;
    cin >> s;
    cin >> t;
    cin >> temp;
    s = s-1;
    for (int j = s; j < t; j++)
      stalls[j]=temp;
  }

  int cost[m], start[m], end[m], coolby[m];
  for (int i = 0; i < m; i++){
    cin >> start[i];
    cin >> end[i];
    cin >> coolby[i];
    cin >> cost[i];
  }
  int res = 100000;

  for (int i = 0; i < (1 << m); i++) {
    int temp = 0;
    int hold = 0;
    int copy[100];
    for (int i = 0; i < 100; i++) {
      temp = stalls[i];
      copy[i] = temp;
    }
    //get set
    vector<int> checkset;
    for (int j = 0; j < m; j++) {
      if (i >> j & 1) {
        checkset.push_back(j);
      }
    }
    //check if set works
    if(checkset.size() == 0) continue;
    if(check(checkset, copy, start, end, coolby)){
      for (int x = 0; x < checkset.size(); x++)
        hold += cost[checkset[x]];
      }
      else hold = 100000000;

    if(hold < res){
      res = hold;
    }
  }
  cout << res << endl;
}
