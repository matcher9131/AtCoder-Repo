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

constexpr ll INF = 1e16;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    auto dijkstra = [&](int root, vector<ll>& dist) {
        fill(dist.begin(), dist.end(), INF);
        dist[root] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
        que.emplace(0, root);
        while (!que.empty()) {
            auto [d, v] = que.top();
            que.pop();
            if (d > dist[v]) continue;
            for (const auto [nv, cost] : g[v]) {
                if (dist[v] + cost < dist[nv]) {
                    dist[nv] = dist[v] + cost;
                    que.emplace(dist[nv], nv);
                }
            }
        }
    };

    vector<ll> d0(n), dn(n);
    dijkstra(0, d0);
    dijkstra(n - 1, dn);

    for (int i = 0; i < n; ++i) {
        cout << d0[i] + dn[i] << endl;
    }

    return 0;
}