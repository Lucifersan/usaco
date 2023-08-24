//#include <bits/stdc++.h>
#include "a_headerfiles.hpp"
using namespace std;
vector<int>milk;
vector<int>capacities;
vector<int>res;

int main(){
  //file input output stuff
  cin.tie(0)->sync_with_stdio(0);
  freopen("walkhome.in", "r", stdin);  
  freopen("walkhome.out", "w", stdout); 
    
  //input to var
  int n;
  cin >> n;
  //this for loop will be the entire code
  for(int i = 0; i < n; i++){
    //input to var pt2 electric boogaloo
    int size, k;
    cin >> size;
    cin >> k;
    char board[size][size+1];
    for (int j = 0; j < size; j++){
      cin >> board[j];
    }
    //Start doing stuff here ig
    if (k==1){
      //stuff
    }
    if (k==2){
      //stuff
    }
    if (k==3){
      //stuff
    }

  }
}

/*
k = 1:
X
X
X
X
XXXXX
^ if possible

XXXXX
    X
    X
    X
    X
^ if possible
- just check if it's possible (N)
- final complexity O(N)

k = 2:
X
X
YYYYY
    X
    X
^ for all rows such that Ys are reachable and uninterrupted

XXY
  Y
  Y
  Y
  YXX
^ for all columns such that Ys are reachable and uninterrupted

- for each row/column (N) you can check if the Y is uninterrupted (N) and if
  reachable using Xs (N)
- final complexity O(N * N)

k = 3:
X
X
YYY
  Z
  ZXX
^ for all row-column pairs such that Ys and Zs are reachable and uninterrupted

XXY
  Y
  YZZ
    X
    X
^ for all row-column pairs such that Ys and Zs are reachable and uninterrupted

- you can check by brute forcing for each row and column (N ^ 2), then checking
  if it's reachable using the Xs (N), then checking if the Ys and Zs are
  uninterrupted (N each)
- final complexity O(N * N * N)
*/