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
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, ll>>> g(n, vector<pair<int, ll>>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        --u; --v;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }

    vector<ll> dist(n, INF);
    dist[0] = a[0];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(a[0], 0);
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[v]) continue;
        for (const auto& [nv, cost] : g[v]) {
            ll newCost = dist[v] + cost + a[nv];
            if (newCost < dist[nv]) {
                dist[nv] = newCost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " \n"[i == n - 1];
    }

    return 0;
}