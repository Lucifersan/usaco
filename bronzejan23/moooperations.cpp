#include <bits/stdc++.h>
//#include "a_headerfiles.hpp"
using namespace std;

bool possible(string moo, int n){
    if (moo.length()<3) return false;
    for (int i = 0; i < n-2; i++){
        if (moo.substr(i, 3) == "MOO" || moo.substr(i, 3) == "OOO" || moo.substr(i, 3) == "OOM" || moo.substr(i, 3) == "MOM")
            return true;
    }
    return false;
}

int count(string moo, int n){
    int res = 100;
    int temp = 100;
    for (int i = 0; i < n-2; i++){
        if (moo.substr(i, 3) == "MOO") temp = 0;
        else if(moo.substr(i, 3) == "OOO") temp = 1;
        else if(moo.substr(i, 3) == "OOM") temp = 2;
        else if(moo.substr(i, 3) == "MOM") temp = 1;

        if (temp < res) res = temp;
  }
  return res;
  
}


int main(){
  //input
  /*freopen("moooperations.in", "r", stdin);  
  freopen("moooperations.out", "w", stdout); */

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    //get input
    string moo;
    cin >> moo;

    if(possible(moo, moo.size())){
        int res = moo.size() - 3 + count(moo, moo.size());
        cout << res << endl;
    }
    else cout << -1 << endl;
  }
}
