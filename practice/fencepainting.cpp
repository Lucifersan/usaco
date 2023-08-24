#include <bits/stdc++.h>
//#include "a_headerfiles.hpp"
using namespace std;

int main(){
    freopen("paint.in", "r", stdin);  
    freopen("paint.out", "w", stdout); 

    int paint[4];
    for (int i = 0; i < 4; i++)
        cin >> paint[i];

    int min = 999;
    int max = -100;
    int minindex;
    int maxindex;
    for (int i = 0; i < 4; i++)
        if (paint[i] < min){
            min = paint[i];
            minindex = i;
        }
    for (int i = 0; i < 4; i++)
        if (paint[i] > max){
            max = paint[i];
            maxindex = i;
        }

    int x, y;
    for (int i = 0; i < 4; i++){
        if(i!=minindex&&i!=maxindex) x = i;
    }
    for (int i = 0; i < 4; i++){
        if(i!=minindex&&i!=maxindex&&i!=x) y = i;
    }

    if (max-min > (paint[1]-paint[0]) + (paint[3]-paint[2])){
        cout << max - min - abs(paint[x]-paint[y]) << endl;
        return 0;
    }
    cout << max - min << endl;
}