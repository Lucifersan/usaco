//#include <bits/stdc++.h>
#include "a_headerfiles.hpp"
using namespace std;
int cuts(int a){
    if (a == 1) return 1;
    else return 2;
}


int main(){
    freopen("herding.in", "r", stdin);  
    freopen("herding.out", "w", stdout); 

    int b, e, m;
    cin >> b;
    cin >> e; 
    cin >> m;

    int be, em, mb;
    be = abs(b - e)-1;
    em = abs(e - m)-1;
    mb = abs (m - b)-1;
    
    if (be > em && be > mb){
        if (em < mb){
            if (em == 0) cout << cuts(mb) << endl;
            else cout << cuts(em) << endl;
            cout << mb << endl;
        }
        else {
            if (mb == 0) cout << cuts(em) << endl;
            else cout << cuts(mb) << endl;
            cout << em << endl;
        }
    }
    if (em > be && em > mb){
        if (be < mb){
            if (be == 0) cout << cuts(mb) << endl;
            else cout << cuts(be) << endl;
            cout << mb << endl;
        }
        else {
            if (mb == 0) cout << cuts(be) << endl;
            else cout << cuts(mb) << endl;
            cout << be << endl;
        }
    }
    if (mb > be && mb > em){
        if (em < be){
            if (em == 0) cout << cuts(be) << endl;
            else cout << cuts(em) << endl;
            cout << be << endl;
        }
        else {
            if (be == 0) cout << cuts(em) << endl;
            else cout << cuts(be) << endl;
            cout << em << endl;
        }
    }
    cout << 0 << endl;
    cout << 0 << endl;

}