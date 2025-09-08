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
#include <atcoder/dsu>
#include <atcoder/scc>
using namespace std;
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    atcoder::dsu d(n);
    vector<pair<int, int>> edge(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        edge[i] = { u, v };
        if (a[u] == a[v]) d.merge(u, v);
    }
    atcoder::scc_graph scc(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        auto [u, v] = edge[i];
        if (a[u] < a[v]) {
            g[d.leader(u)].push_back(d.leader(v));
            scc.add_edge(d.leader(u), d.leader(v));
        } else if (a[v] < a[u]) {
            g[d.leader(v)].push_back(d.leader(u));
            scc.add_edge(d.leader(v), d.leader(u));
        }
    }

    vector<int> tp;
    vector<int> revTp(n, -1);
    for (const auto &vec : scc.scc()) {
        int v = vec[0];
        revTp[v] = (int)tp.size();
        tp.push_back(v);
    }
    vector<int> dp(n);
    dp[revTp[d.leader(0)]] = 1;
    for (int i = revTp[d.leader(0)]; i < n; ++i) {
        int from = tp[i];
        for (const int to : g[from]) {
            dp[revTp[to]] = max(dp[revTp[to]], dp[i] + 1);
        }
    }

    cout << dp[revTp[d.leader(n-1)]] << endl;

    return 0;
}