#include <bits/stdc++.h>
//include "a_headerfiles.hpp"
using namespace std;

bool beats(int dice1[], int dice2[]){
    int probWins = 0;
    int probLoses = 0;
    for(int x = 0; x < 4; x++){
        for(int y = 0; y < 4; y++){
            if(dice1[x]>dice2[y])
                probWins++;    
            if(dice1[x]<dice2[y])
                probLoses++;
        }
    }
    return (probWins > probLoses);
}

string transitive(int diceA[], int diceB[]){
    int diceC[4];
    for(int a = 1; a <= 10; a++){
        for(int b = 1; b <= 10; b++){
            for(int c = 1; c <= 10; c++){
                for(int d = 1; d <= 10; d++){
                    diceC[0]=a;
                    diceC[1]=b;
                    diceC[2]=c;
                    diceC[3]=d;
                    
                    //check if C makes it transitive
                    if (beats(diceB,diceC)&&beats(diceC,diceA)&&beats(diceA,diceB)){
                        return "yes";
                    }   
                    else if (beats(diceC,diceB)&&beats(diceA,diceC)&&beats(diceB,diceA))
                        return "yes";
                }
            }
        }
    }
    return "no";
}

int main(){
  //file input output stuff
  cin.tie(0)->sync_with_stdio(0);
  //freopen("nontransitivedice.in", "r", stdin);  
  //freopen("nontransitivedice.out", "w", stdout); 
    
  //input to var
  int n;
  cin >> n;
  //this for loop will be the entire code
  for(int i = 0; i < n; i++){
    //input to var pt2 electric boogaloo
    int diceA[4] = {0,0,0,0};
    int diceB[4] = {0,0,0,0};
    for (int j = 0; j < 4; j++){
      cin >> diceA[j];
    }
    for (int k = 0; k < 4; k++){
      cin >> diceB[k];
    }

    cout << transitive(diceA, diceB) << endl;

    }
}