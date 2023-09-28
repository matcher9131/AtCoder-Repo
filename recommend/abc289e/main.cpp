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

constexpr int INF = 1e8;

int main() {
    int t;
    cin >> t;

    auto run = []() {
        int n, m;
        cin >> n >> m;
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<vector<int>> dist(n, vector<int>(n, INF));
        dist[0][n - 1] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
        que.emplace(0, 0, n - 1);
        while (!que.empty()) {
            auto [d, v1, v2] = que.top();
            que.pop();
            if (d > dist[v1][v2]) continue;
            for (const int nv1 : g[v1]) {
                for (const int nv2 : g[v2]) {
                    if (c[nv1] == c[nv2]) continue;
                    if (dist[v1][v2] + 1 < dist[nv1][nv2]) {
                        dist[nv1][nv2] = dist[v1][v2] + 1;
                        que.emplace(dist[nv1][nv2], nv1, nv2);
                    }
                }
            }
        }

        return dist[n - 1][0];
    };

    for (int i = 0; i < t; ++i) {
        int ans = run();
        cout << (ans == INF ? -1 : ans) << endl;
    }

    return 0;
}