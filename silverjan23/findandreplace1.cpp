#include <bits/stdc++.h>
//#include "a_headerfiles.hpp"
using namespace std;      


bool isIn(vector<char> arr, char a){
    if (arr.size()==0) return false;
    for(int i = 0; i < arr.size(); i++)
        if (arr[i] == a) return true;
    return false;
}

bool isIn(string stuff, char search){
    for (int i = 0; i < stuff.length(); i++)
        if (stuff[i] == search) return true;
    return false;
}

int uniqueChars(string stuff){
    int res = 0;
    for (int i = 0; i < stuff.length(); i++)
        if(!isIn(stuff, stuff[i])) res++;
    return res;
}

void replaceWith(string& initial, string goal, char a, char b){
    for (int i = 0; i < initial.length(); i++)
        if(initial[i]==a) initial[i]=b;
}

bool isPossible(string initial, string goal){
    //0 to 25 is A-Z, 26 to 51 is a-z
    vector<vector<char> > arr;
    arr.resize(100);
    for (int i = 0; i < initial.length(); i++){
        if(!isIn(arr[int(initial[i])-65], goal[i]))
            arr[int(initial[i])-65].push_back(goal[i]);
    }
    for (int i = 0; i < arr.size(); i++)
        if(arr[int(initial[i])-65].size()>1) return false;
    return true;
}

bool otherSwitches(string initial, string goal, char g){
    for (int i = 0; i < initial.length(); i++){
        if (initial[i]==g&&g!=goal[i]) return true;
    }
    return false;
}

char findOtherSwitchInitial(string initial, string goal, char g){
    for (int i = 0; i < initial.length(); i++){
        if (initial[i]==g&&g!=goal[i]) {
            return initial[i];
        }
    }
    return '*';
}

char findOtherSwitchGoal(string initial, string goal, char g){
    for (int i = 0; i < initial.length(); i++){
        if (initial[i]==g&&g!=goal[i]) {
            return goal[i];
        }
    }
    return '*';
}
      

int main(){
  //input
  /*freopen("findandreplace.in", "r", stdin);  
  freopen("findandreplace.out", "w", stdout); */

  int n;
  cin >> n;

  for (int i = 0; i < n; i++){
    //more input getting
    string initial, goal;
    cin >> initial;
    cin >> goal;
    int l = initial.length();
    int res = 0;

    //if its possible, do stuff
    if (isPossible(initial, goal)){
        for (int j = 0; j < l; j++){
            if (initial[j]!=goal[j]){
                //stuff??
                if (otherSwitches(initial, goal, goal[j])) {
                    res +=3;
                    replaceWith(initial, initial[j], '*');
                    replaceWith(initial, findOtherSwitchInitial(initial, goal, goal[j]), findOtherSwitchGoal(initial, goal, goal[j]));
                    replaceWith(initial, '*', goal[j]);
                }
                else {
                    res += 1;
                    replaceWith(initial, initial[j], goal[j]);
                }
            }
        }
        cout << res << endl;
    }
    //if its not possible, print -1
    else cout << -1 << endl;
    
    }
  }



