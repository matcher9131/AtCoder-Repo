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
#include <numeric>
using namespace std;
using ll = long long;

constexpr int INF = 1e8;

int n, m;
int s, t;
vector<vector<pair<int, int>>> g;

void dijkstra(int from, vector<int> &d) {
    d[from] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.emplace(0, from);
    while (!que.empty()) {
        auto [dist, v] = que.top();
        que.pop();
        if (dist > d[v]) continue;
        for (const auto [nv, cost] : g[v]) {
            if (d[v] + cost < d[nv]) {
                d[nv] = d[v] + cost;
                que.emplace(d[nv], nv);
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> t;
    --s; --t;
    g = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
        int x, y, d;
        cin >> x >> y >> d;
        --x; --y;
        g[x].emplace_back(y, d);
        g[y].emplace_back(x, d);
    }
    vector<int> ds(n, INF), dt(n, INF);
    dijkstra(s, ds);
    dijkstra(t, dt);

    for (int i = 0; i < n; ++i) {
        if (i == s || i == t || ds[i] == INF || dt[i] == INF) continue;
        if (ds[i] == dt[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}