#include <bits/stdc++.h>
//#include "a_headerfiles.hpp"
using namespace std;

int getcowsfrom(vector<int>& indices, int start, int end){
    //get locations
    int leftBound = lower_bound(indices.begin(), indices.end(), start) - indices.begin();
    int rightBound = upper_bound(indices.begin(), indices.end(), end) - indices.begin();
    return (rightBound - leftBound);
  
}


int main(){
    //set up input
    /*freopen("leaders.in", "r", stdin);  
    freopen("leaders.out", "w", stdout); */
  
    //get input
    int n;
    cin >> n;
    string allcows;
    cin >> allcows;
    int lists[n] ;
    for (int i = 0; i < n; i++)
        cin >> lists[i];

    //get vectors with the locations of all the Gs and all the Hs
    vector<int> locG, locH;
    for (int i = 0; i < allcows.size(); i++) {
        if (allcows.substr(i,1) =="H") locH.push_back(i);
        }
        for (int i = 0; i < allcows.size(); i++) {
        if (allcows.substr(i,1) == "G") locG.push_back(i);
        }

    //make a vector with the location of all the G leaders and all the H leaders
    vector<int> leadersG, leadersH, notleaders;
    for (int i = 0; i < n; i++){
        if (locG.size()==getcowsfrom(locG, i, i + lists[i]) && allcows.substr(i,1) == "G") 
            leadersG.push_back(i);
        if (locH.size()==getcowsfrom(locH, i, i + lists[i]) && allcows.substr(i,1) == "H")
            leadersH.push_back(i);
        else notleaders.push_back(i);
    }

    //get # of G leaders and # of H leaders and multiply–this ends case1
    int res = leadersG.size()*leadersH.size();

    //now check for # of leader pairs where one cow has the other breed's leader in its list
    for (int i = 0; i < n; i++){
        if (count(leadersG.begin(), leadersG.end(), i) > 0||count(leadersH.begin(), leadersH.end(), i) > 0)
            continue;
        if (allcows.substr(i, 1) == "G") res += getcowsfrom(leadersH, i, lists[i]-1);
        if (allcows.substr(i, 1) == "H") res += getcowsfrom(leadersG, i, lists[i]-1);
    }
  //return result
  cout << res;
}
