#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> earliest_arrival_time(int N, int M, vector<vector<int>>& flights, vector<int>& layovers) {
    // initialize distances to infinity except for (1,0)
    vector<vector<int>> dist(N+1, vector<int>(10'000'001, INF));
    dist[1][0] = 0;

    // priority queue to store vertices to be processed
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {1, 0}});

    while (!pq.empty()) {
        // get vertex with smallest distance
        auto [d, vertex] = pq.top();
        pq.pop();
        int i = vertex.first, t = vertex.second;

        // check if vertex has already been processed
        if (d > dist[i][t]) {
            continue;
        }

        // consider all flights departing from airport i
        for (auto [j, rj, sj] : flights[i]) {
            // compute arrival time at airport j
            int s = t + (sj - rj) + layovers[j];

            // check if this flight leads to a better path
            if (s < dist[j][s]) {
                dist[j][s] = s;
                pq.push({s, {j, s}});
            }
        }
    }

    // output earliest arrival time to each airport
    vector<int> result;
    for (int i = 1; i <= N; i++) {
        int earliest = INF;
        for (int t = 0; t <= 10'000'000; t++) {
            if (dist[i][t] != INF) {
                earliest = min(earliest, dist[i][t]);
            }
            else {
                break;
            }
        }
        result.push_back(earliest == INF ? -1 : earliest);
    }
    return result;
}

int main() {

    #if defined(LUCIFER_SAN)
  freopen("mooroute.in", "r", stdin);
  freopen("mooroute.out", "w", stdout);
#endif // defined(LUCIFER_SAN)
  cin.tie(0)->sync_with_stdio(0);

  
    int N, M;
    cin >> N >> M;

    // read in flights and layovers
    vector<vector<int>> flights(N+1);
    for (int j = 0; j < M; j++) {
        int c, d, r, s;
        cin >> c >> d >> r >> s;
        flights[c].push_back(c);
        flights[c].push_back(d);
        flights[c].push_back(r);
        flights[c].push_back(s);
    }
    vector<int> layovers(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> layovers[i];
    }

    // compute earliest arrival time to each airport
    auto result = earliest_arrival_time(N, M, flights, layovers);

    // output result
    for (int i = 1; i <= N; i++) {
        cout << result[i-1] << "\n";
    }
    return 0;
}
