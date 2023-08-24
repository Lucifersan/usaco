#include <iostream>
#include <cstdio>
#include <vector>
#if defined(LUCIFER_SAN)
  #include "a_headerfiles.hpp"
#else 
  #include <bits/stdc++.h>
#endif // defined(LUCIFER_SAN)
 
using namespace std;

int main()
{
    int n, Tmax;
    cin >> n >> Tmax;
    int durations[n];
    for (int i = 0; i < n; i++)
        cin >> durations[i];

    auto simulate = [&](int K)
    {
        int time = 0, i = 0;
        deque<int> stage;
        for (; i < K; i++)
        {
            time += durations[i];
            stage.push_back(durations[i]);
        }
        sort(stage.begin(), stage.end());
        while (i < n || !stage.empty())
        {
            int next_cow = i < n ? durations[i++] : INT_MAX;
            int finished_cow = stage.front();
            stage.pop_front();
            time += finished_cow;
            if (time > Tmax)
                return false;
            if (next_cow < INT_MAX)
            {
                stage.push_back(next_cow);
                sort(stage.begin(), stage.end());
            }
        }
        return true;
    };

    int lo = 1, hi = n;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (simulate(mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    cout << lo - 1 << endl;
    return 0;
}