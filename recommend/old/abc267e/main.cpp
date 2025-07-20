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


int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> g(n, vector<int>());
    vector<ll> cost(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u] += a[v];
        cost[v] += a[u];
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    for (int i = 0; i < n; ++i) {
        que.emplace(cost[i], i);
    }
    ll answer = 0;
    while (!que.empty()) {
        auto [c, v] = que.top();
        que.pop();
        if (a[v] == 0) continue;

        answer = max(answer, c);
        for (const int nv : g[v]) {
            cost[nv] -= a[v];
            que.emplace(cost[nv], nv);
        }
        a[v] = 0;
    }

    cout << answer << endl;

    return 0;
}