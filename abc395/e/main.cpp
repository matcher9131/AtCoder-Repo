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
#include <functional>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

int main() {
    int n, m;
    ll x;
    cin >> n >> m >> x;
    vector<vector<pair<int, ll>>> g(2 * n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].emplace_back(b, 1);
        g[b].emplace_back(n + a, x + 1);
        g[n + b].emplace_back(n + a, 1);
        g[n + a].emplace_back(b, x + 1);
    }

    vector<ll> dist(2 * n, INF);
    dist[0] = 0;
    // [d, v]
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        auto [c, v] = que.top();
        if (v == n - 1 || v == 2 * n - 1) {
            cout << c << endl;
            return 0;
        }
        que.pop();
        if (c > dist[v]) continue;
        for (const auto& [nv, cost] : g[v]) {
            if (dist[v] + cost < dist[nv]) {
                dist[nv] = dist[v] + cost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    return 0;
}