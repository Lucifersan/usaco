#include <bits/stdc++.h>
//#include "a_headerfiles.hpp"
using namespace std;


int main(){
    //file input output stuff
    cin.tie(0)->sync_with_stdio(0);
    freopen("lostcow.in", "r", stdin);  
    freopen("lostcow.out", "w", stdout); 


    //stdin to vars
    int x,y;
    cin>>x;
    cin>>y;

    int location, modifier, distance, prevlocation;
    modifier = 1;
    location = x;
    prevlocation = location;
    distance = 0;
    bool notaty = true;

    while(notaty){
        for(int i = 0; i < abs(x-prevlocation)+abs(modifier); i++){
            distance++;
            //update location
            if (modifier > 0) 
                location += 1;
            else location -= 1;

            //check if at y
            if (location == y) {
                notaty = false;
                break;
            }
        }
        //update modifier
        modifier *= -2;
        prevlocation = location;
    }

    cout << distance;
}