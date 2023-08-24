#include <iostream>
#include <cstdio>
#include <vector>
#if defined(LUCIFER_SAN)
  #include "a_headerfiles.hpp"
#else 
  #include <bits/stdc++.h>
#endif // defined(LUCIFER_SAN)
 
using namespace std;
/*int minUpgradeCostCookies(int a, int b, int c, int tc, int tm){
    int cost = 0;
    while((tc*a + tm*b) - c > 0){
        if (max (tc*a, tm*b) == tc*a && tc >= 0){
            cost ++;
            tc--;
        }
        if (max (tc*a, tm*b) == tm*b && tm >= 0){
            //cost++;
            tm--;
        }
    }
    return cost;
}
int minUpgradeCostMuffins(int a, int b, int c, int tc, int tm){
    int cost = 0;
    while((tc*a + tm*b) - c > 0){
        if (max (tc*a, tm*b) == tc*a && tc >= 0){
            //cost ++;
            tc--;
        }
        if (max (tc*a, tm*b) == tm*b && tm >= 0){
            cost++;
            tm--;
        }
    }
    return cost;
}*/

int minUpgradeCost(int a, int b, int c, int tc, int tm){
    int cost = 0;
    while((tc*a + tm*b) - c > 0){
        if (max (tc*a, tm*b) == tc*a && tc >= 0){
            cost ++;
            tc--;
        }
        if (max (tc*a, tm*b) == tm*b && tm >= 0){
            cost++;
            tm--;
        }
    }
    return cost;
}

/*bool check(const vector<int>& a, const vector<int>& b, const vector<int>& c,int n, int tc, int tm){
    for (int i = 0; i < n; i++){
        if ((tc*a[i] + tm*b[i]) > c[i])
            return false;
    }
    return true;
}

vector<int> checkReturn(const vector<int>& a, const vector<int>& b, const vector<int>& c,int n, int tc, int tm, int tempc, int tempm){
    vector<int> res;
    res.push_back(0);
    res.push_back(0);
    int maxC = 0;
    int maxM = 0;
    for (int i = 0; i < n; i++){
        if (!check(a,b,c,n,tc-tempc,tm-tempm)){
            if(tempc < minUpgradeCostCookies(a[i], b[i], c[i], tc, tm)){
                if (maxC < minUpgradeCostCookies(a[i], b[i], c[i], tc, tm))
                maxC = minUpgradeCostCookies(a[i], b[i], c[i], tc, tm);
            }
            if(tempm < minUpgradeCostMuffins(a[i], b[i], c[i], tc, tm)){
                if (maxM < minUpgradeCostMuffins(a[i], b[i], c[i], tc, tm))
                maxM = minUpgradeCostMuffins(a[i], b[i], c[i], tc, tm);
            }
        }
    }
    res[0]=maxC;
    res[1]=maxM;
    return res;
}*/

int main(void) {
#if defined(LUCIFER_SAN)
  freopen("bakery.in", "r", stdin);
  freopen("bakery.out", "w", stdout);
#endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  for (int q = 0; q < t; q++){

    long long int n, tc, tm, temp, max;
    long long int tempC, tempM;
    max = 0;

    cin >> n >> tc >> tm;

    vector<int> a, b, c;

    for (int i = 0; i < n; i++){
        int a1, b1, c1;
        cin >> a1 >> b1 >> c1;
        a.push_back(a1);
        b.push_back(b1);
        c.push_back(c1);
    }

    for (int i = 0; i < n; i++){
        temp = minUpgradeCost(a[i], b[i], c[i], tc, tm);
        //tempC =  minUpgradeCostMuffins(a[i], b[i], c[i], tc, tm);
        //tempM =  minUpgradeCostCookies(a[i], b[i], c[i], tc, tm);

        if (temp > max /*&& check(a, b, c, n, tc-tempC, tm-tempM)*/) 
            max = temp;
        /*else if (temp > max && !check(a, b, c, n, tc-tempC, tm-tempM)) {
            vector<int> hii = checkReturn(a, b, c, n, tc, tm, tempC, tempM);
            tempC += hii[0];
            tempM += hii[1];
            if (tempC + tempM > max && (hii[0]==0 || hii[1]==0)){
                max = tempM + tempC;
            }
        }*/
    }
    cout << max << endl;
  }
}