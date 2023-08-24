#include <iostream>
#include <cstdio>
#include <vector>
#if defined(LUCIFER_SAN)
#include "a_headerfiles.hpp"
#else
#include <bits/stdc++.h>
#endif // defined(LUCIFER_SAN)

using namespace std;
const int N = 1e5;
vector<int> adjs[N]; // Adjacent edges to each node
bool viss[N];        // Whether node has been visited

// Depth-first-search
void dfs(int a)
{
    // If visited, skip
    if (viss[a])
        return;
    viss[a] = true;

    // Visit adjacent nodes
    for (auto b : adjs[a])
    {
        dfs(b);
    }
}

bool checkConnected(const vector<int> &cow1, const vector<int> &cow2)
{
    int distance;
    if (cow1.empty() || cow2.empty())
        return false;
    // sqrt(deltaX^2 + deltay^2)
    distance = (cow2[0] - cow1[0]) * (cow2[0] - cow1[0]) + (cow2[1] - cow1[1]) * (cow2[1] - cow1[1]);
    if (distance > cow1[2] * cow1[2])
        return false;
    else
        return true;
}

int main(void)
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> cows[n];

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int a, b, p;
        cin >> a >> b >> p;
        cows[i].push_back(a);
        cows[i].push_back(b);
        cows[i].push_back(p);
    }

    // Read edges
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (checkConnected(cows[i], cows[j]) && i != j){
                adjs[i].push_back(j);
            }
        }
    }
    // Traverse
    int max, count;
    max = 0;
    count = 0;
    for (int i = 0; i < n; i++)
    {
        dfs(i);
        for (int j = 0; j < n; j++){
            if (viss[j]) count++;
        }
        if (count > max) max = count;
        count = 0;
        for (int i = 0; i < n; i++){
            viss[i] = false;
        }
    }

    cout << max << endl;
}