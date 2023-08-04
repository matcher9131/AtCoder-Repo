#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> self;
vector<vector<int>> dist;

void dijkstra(int from) {
    vector<int> d(n, INF);
    d[from] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.emplace(0, from);
    while (!que.empty()) {
        auto [d0, v] = que.top();
        que.pop();
        if (d0 > d[v]) continue;
        for (const auto [cost, nv] : g[v]) {
            if (d[v] + cost < d[nv]) {
                d[nv] = d[v] + cost;
                que.emplace(d[nv], nv);
            }
        }
    }

    dist[from] = d;
}

int main() {   
    cin >> n >> m;
    g = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
    self = vector<int>(n, INF);
    dist = vector<vector<int>>(n, vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        if (a == b) {
            self[a] = min(self[a], c);
        } else {
            g[a].emplace_back(c, b);
        }
    }


    for (int i = 0; i < n; ++i) {
        dijkstra(i);
    }

    for (int i = 0; i < n; ++i) {
        int minDist = self[i];
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int d = dist[i][j] + dist[j][i];
            if (d < minDist) minDist = d;
        }
        cout << (minDist >= INF ? -1 : minDist) << endl;
    }

    return 0;
}