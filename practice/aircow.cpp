//#include <bits/stdc++.h>
#include "a_headerfiles.hpp"

using namespace std;
vector<int>goal;
vector<int>initial;
vector<int>difference;

int main(){
    //make code faster
    cin.tie(0)->sync_with_stdio(0);

    //stdin to vars
    int n;
    cin>>n;

    int temp;
    for(int i = 0;i < n; i++) {
        cin >> temp;
        goal.push_back(temp);
    }
    for(int i = 0; i<n; i++) {
        cin >> temp;
        initial.push_back(temp);
        difference.push_back(goal[i]-initial[i]); // difference vector
    }

    //do thing?
    int res = abs(difference[0]);
    bool pos;
    bool prevpos;
    for(int i = 1;i<n;i++){
        if (difference[i] == 0) 
            continue;

        prevpos=difference[i-1]>0;
        pos = difference[i]>0;

        if (pos) {
            if (prevpos!=pos){
                res+=abs(difference[i]); 
                continue;
            } else if (difference[i]-difference[i-1]>0)
                res += difference[i]-difference[i-1];
        } else{
            if (prevpos!=pos){
                res+=abs(difference[i]); 
                continue;
            } else if (difference[i]-difference[i-1]<0)
                res += abs(difference[i]-difference[i-1]);
        }
    }
    
    cout << res;
}