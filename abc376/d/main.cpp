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

constexpr int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    // 頂点0への辺を持つ頂点番号
    vector<int> toZero;
    for (int i = 0; i < m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;
        g[ai].push_back(bi);
        if (bi == 0) toZero.push_back(ai);
    }

    vector<int> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[v]) continue;
        for (const int nv : g[v]) {
            if (dist[v] + 1 < dist[nv]) {
                dist[nv] = dist[v] + 1;
                que.emplace(dist[nv], nv);
            }
        }
    }

    int ans = INF;
    for (const int v : toZero) {
        if (dist[v] == INF) continue;
        ans = min(ans, dist[v] + 1);
    }

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}