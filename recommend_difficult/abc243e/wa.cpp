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

constexpr ll INF = 1e16;

int n, m;
vector<vector<pair<int, ll>>> g;
vector<vector<bool>> used;

void dijkstra(int root, vector<ll>& dist) {
    vector<int> prev(n, -1);
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
                // 経路復元
                prev[nv] = v;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (prev[i] != -1) {
            used[i][prev[i]] = true;
            used[prev[i]][i] = true;
        }
    }
}

int main() {
    cin >> n >> m;
    g = vector<vector<pair<int, ll>>>(n, vector<pair<int, ll>>());
    used = vector<vector<bool>>(n, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    vector<ll> dist(n);
    for (int i = 0; i < n; ++i) {
        dijkstra(i, dist);
    }

    int c = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (used[i][j]) ++c;
        }
    }

    cout << m - c << endl;

    return 0;
}