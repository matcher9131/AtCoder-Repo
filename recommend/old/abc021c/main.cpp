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

constexpr int INF = 1000;
constexpr int MOD = 1e9 + 7;

int main() {
    int n, m, a, b;
    cin >> n >> a >> b >> m;
    --a;
    --b;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> dist(n, INF);
    dist[a] = 0;
    vector<int> count(n);
    count[a] = 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.emplace(0, a);
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[v]) continue;
        for (const auto nv : g[v]) {
            if (dist[v] + 1 < dist[nv]) {
                dist[nv] = dist[v] + 1;
                count[nv] = count[v];
                que.emplace(dist[nv], nv);
            } else if (dist[v] + 1 == dist[nv]) {
                count[nv] += count[v];
                count[nv] %= MOD;
            }
        }
    }

    cout << count[b] << endl;

    return 0;
}