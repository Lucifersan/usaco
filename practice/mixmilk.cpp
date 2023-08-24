//#include <bits/stdc++.h>
#include "a_headerfiles.hpp"
using namespace std;
vector<int>milk;
vector<int>capacities;
vector<int>res;



int min(int a, int b, int c) {
    return min(a, min(b, c));
}


int main(){
    //file input output stuff
    cin.tie(0)->sync_with_stdio(0);
    freopen("mixmilk.in", "r", stdin);  
    freopen("mixmilk.out", "w", stdout); 

    int temp;
    for(int i = 0; i < 3; i++){
        cin >> temp;
        capacities.push_back(temp);
        cin >> temp;
        milk.push_back(temp);
    }

    int sum=0;
    for(int i = 0; i < 3; i++){
        sum += milk[i];
    }

    /*res.push_back(0);
    res.push_back(minimum(capacities[0],capacities[1], sum));
    res.push_back(0);

    sum -= minimum(capacities[0],capacities[1], sum);
    if (sum != 0){
        res[2]=min(sum, capacities[2]);
        sum -= min(sum, capacities[2]);
        if(sum!=0)
            res[0] = sum;
    }

    //return
    for(int i = 0; i < 3; i++){
        cout << res[i] << endl;
    }*/

    /*10 32 7
    0
       20
          1*/
    
    int amtPoured;
    for(int i = 0; i < 4; i++){
        amtPoured = min(capacities[(i+1)%3]-milk[(i+1)%3], milk[i%3]);
        milk[(i+1)%3] += amtPoured;
        milk[i%3] -= amtPoured;
    }

    for(int i = 0; i < 3; i++){
        cout << milk[i] << endl;
    }


}