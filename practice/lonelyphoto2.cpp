#include <bits/stdc++.h>
//#include "a_headerfiles.hpp"

using namespace std;
vector<int>check;
/*
what if u go thru and check any spots where there is just
a single g or h chilling

uhhh so u find a single g or h chilling
so like if its a g
u check in the left direction until u hit another g
and same for the right

take the num of charas on either side and add 1 (to account for the 0 option)
multiply and subtract 3

add it up

return

*/

int main(){
    //make code faster
    cin.tie(0)->sync_with_stdio(0);
    //freopen("lonelyphoto.in", "r", stdin);  
    //freopen("lonelyphoto.out", "w", stdout); 

    //stdin to vars
    long long int n;
    cin>>n;
    string pic;
    cin>> pic;

    if(pic[0] != pic[1] && pic[0] != pic[2] )
        check.push_back(0);
    if(pic[n-1] != pic[n-2] && pic[n-1] != pic[n-3] )
        check.push_back(n-1);

    //find all the single letters chilling
    for (int i = 1; i < n-1; i++){
        bool a = pic[i] == pic[i-1];
        bool b = pic[i] == pic[i+1];
        if(pic[i] == pic[i-1] && pic[i] == pic[i+1])
            continue;
        else
            check.push_back(i);
    }

    //for each possible index, check in both directions
    long long int left = 1;
    long long int right = 1;
    long long int index;
    long long int result;
    result = 0;
    for (int i = 0; i < check.size(); i++){
        left = 1;
        right = 1;
        index = check[i];
        while (index-left >= 0 && pic[index-left] != pic[index]){
            left++;
        }
        while (index+right < pic.length() && pic[index+right] != pic[index]){
            right++;
        }
        if (left == 1 || right == 1) 
            result += left * right - 2;
        else 
            result += (left * right) - 3;
    }

    cout << result;
}