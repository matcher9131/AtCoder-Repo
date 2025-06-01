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

constexpr ll INF = 9e18;

int main() {
    int n, m;
    cin >> n >> m;
    // dst, edgeNo
    vector<vector<pair<int, int>>> g(n);
    vector<tuple<ll, ll, ll, ll>> edges(m);
    for (int ei = 0; ei < m; ++ei) {
        ll l, d, k, c;
        int a, b;
        cin >> l >> d >> k >> c >> a >> b;
        --a; --b;
        g[b].emplace_back(a, ei);
        edges[ei] = { l, d, k, c };
    }

    vector<ll> lastTime(n, -1);
    lastTime[n-1] = INF;
    priority_queue<pair<ll, int>> que;
    que.emplace(INF, n-1);
    while (!que.empty()) {
        auto [lt, v] = que.top();
        que.pop();
        if (lt < lastTime[v]) continue;
        for (const auto& [nv, ei] : g[v]) {
            auto [l, d, k, c] = edges[ei];
            ll kMax = min(k, 1 + (lt - c - l) / d);
            ll nvlt = l + (kMax - 1) * d;
            if (nvlt > lastTime[nv]) {
                lastTime[nv] = nvlt;
                que.emplace(nvlt, nv);
            }
        }
    }

    for (int i = 0; i < n-1; ++i) {
        if (lastTime[i] == -1) {
            cout << "Unreachable" << endl;
        } else {
            cout << lastTime[i] << endl;
        }
    }

    return 0;
}