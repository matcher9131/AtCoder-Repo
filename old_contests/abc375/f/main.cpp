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
    int n, m, nq;
    cin >> n >> m >> nq;
    vector<tuple<int, int, ll>> e(m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        e[i] = make_tuple(a, b, c);
    }
    vector<tuple<int, int, int>> q(nq);
    unordered_set<int> erased;
    for (int i = 0; i < nq; ++i) {
        int k;
        cin >> k;
        if (k == 1) {
            int ei;
            cin >> ei;
            --ei;
            q[i] = make_tuple(1, ei, 0);
            erased.insert(ei);
        } else {
            int x, y;
            cin >> x >> y;
            --x; 
            --y;
            q[i] = make_tuple(2, x, y);
        }
    }
    reverse(q.begin(), q.end());

    vector<vector<ll>> g(n, vector<ll>(n, INF));
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for (int i = 0; i < m; ++i) {
        if (!erased.contains(i)) {
            auto [a, b, c] = e[i];
            g[a][b] = c;
            g[b][a] = c;
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }

    // Warshall-Floyd
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    vector<ll> answers;
    for (const auto& [k, x, y] : q) {
        if (k == 1) {
            auto [u, v, c] = e[x];
            // 繋げた辺を使って各頂点間の距離を更新
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], min(dist[i][u] + c + dist[v][j], dist[i][v] + c + dist[u][j]));
                }
            }
        } else {
            answers.push_back(dist[x][y]);
        }
    }

    reverse(answers.begin(), answers.end());
    for (const ll ans : answers) {
        cout << (ans < INF ? ans : -1) << endl;
    }

    return 0;
}