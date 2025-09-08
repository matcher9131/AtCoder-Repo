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
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    vector<tuple<int, int, ll>> edge(m);
    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll t;
        cin >> u >> v >> t;
        --u; --v;
        d[u][v] = min(d[u][v], t);
        d[v][u] = min(d[v][u], t);
        edge[i] = {u, v, t};
    }
    int nq;
    cin >> nq;
    vector<vector<int>> q(nq);
    for (int i = 0; i < nq; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int bij;
            cin >> bij;
            --bij;
            q[i].push_back(bij);
        }
        sort(q[i].begin(), q[i].end());
    }
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int qi = 0; qi < nq; ++qi) {
        int k = q[qi].size();
        ll ans = INF;
        do {
            for (int bit = 0; bit < (1 << k); ++bit) {
                ll sum = 0;
                int v = 0;
                for (int i = 0; i < k; ++i) {
                    auto [u1, u2, t] = edge[q[qi][i]];
                    if (bit & 1 << i) {
                        swap(u1, u2);
                    }
                    sum += d[v][u1] + t;
                    v = u2;
                }
                sum += d[v][n - 1];
                ans = min(ans, sum);
            }
        } while (next_permutation(q[qi].begin(), q[qi].end()));
        cout << ans << endl;
    }

    return 0;
}