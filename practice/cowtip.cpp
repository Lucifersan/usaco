//#include <bits/stdc++.h>
#include "a_headerfiles.hpp"
using namespace std;

/*void replace(vector < vector <int> > &arr, int row, int col){
    for(int i = 0; i < row; i ++) for (int j = 0; j < col; j++){
        if (arr[i][j] == 0) arr[i][j] = 1;
        else arr[i][j] = 0;
    }
}*/

bool hasOne(vector < vector <int> > arr, int n){
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
        if (arr[i][j] == 1) return true;}
    return false;

}

int lastOneRow(vector < vector <int> > arr, int n){
    for (int i = (n-1); i >=0; i--) for (int j = (n-1); j >= 0; j--){
        if (arr[j][i] == 1) return j;
    }
    return -1;
}

int lastOneCol(vector < vector <int> > arr, int n){
    for (int i = n-1; i >=0; i--) for (int j = (n-1); j >= 0; j--){
        if (arr[j][i] == 1) return i;
    }
    return -1;
}

int main(){
    //input
    vector< vector <int> > field;
    //freopen("cowtip.in", "r", stdin);  
    //freopen("cowtip.out", "w", stdout); 
    int n;
    string temp;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        vector <int> line;
        for (int j = 0; j < n; j++){
            if(temp[j]=='1') line.push_back(1);
            else line.push_back(0);
        }
        field.push_back(line);
    }

    //stuff
    int moves=0;
    while(hasOne(field, n)){
        moves++;
        int row = lastOneRow(field,n);
        int col = lastOneCol(field,n);
        for(int i = 0; i <= row; i++) for (int j = 0; j <= col; j++){
            if (field[i][j] == 0) 
                field[i][j] = 1;
            else if (field[i][j]==1)
                field[i][j]=0;
        }
    }
    cout << moves << endl;
    
}