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
#include <atcoder/convolution>
using namespace std;
using ll = long long;

class Rerooting {
public:
    struct DP {
        ll dp;
        DP(ll dp_) : dp(dp_) {}
    };
    struct Edge {
        int to;
    };
    using Graph = vector<vector<Edge>>;

private:
    // 単位元（葉のDPの値はadd_root(identity)になる）
    const DP id = DP(-1);
    // 二項演算
    function<DP(DP, DP)> merge = [](DP acc, DP d) -> DP {
        return DP(max(acc.dp, d.dp));
    };
    // 新たな部分木のDPを計算
    function<DP(DP)> get_subtree_root = [](DP d) -> DP {
        return DP(d.dp + 1);
    };
    vector<vector<DP>> dp;
    Graph G;
    
public:
    vector<DP> ans;
    Rerooting(int N) : G(N) {
        dp.resize(N);
        ans.assign(N, id);
    }
    void add_edge(int a, int b) {
        G[a].push_back({b});
    }
    void build() {
        dfs(0);
        bfs(0, id);
    }

private:
    DP dfs(int v, int p = -1) {
        DP acc = id;
        int deg = G[v].size();
        dp[v] = vector<DP>(deg, id);
        for (int i = 0; i < deg; i++) {
            int u = G[v][i].to;
            if (u == p) continue;
            dp[v][i] = dfs(u, v);
            acc = merge(acc, dp[v][i]);
        }
        return get_subtree_root(acc);
    }
    void bfs(int v, const DP& dp_p, int p = -1) {
        int deg = G[v].size();
        for (int i = 0; i < deg; i++) {
            if (G[v][i].to == p) dp[v][i] = dp_p;
        }
        vector<DP> dp_l(deg + 1, id), dp_r(deg + 1, id);
        for (int i = 0; i < deg; i++) {
            dp_l[i + 1] = merge(dp_l[i], dp[v][i]);
        }
        for (int i = deg - 1; i >= 0; i--) {
            dp_r[i] = merge(dp_r[i + 1], dp[v][i]);
        }
        ans[v] = get_subtree_root(dp_l[deg]);
        for (int i = 0; i < deg; i++) {
            int u = G[v][i].to;
            if (u == p) continue;
            bfs(u, get_subtree_root(merge(dp_l[i], dp_r[i + 1])), v);
        }
    }
};

int main() {
    int n1;
    cin >> n1;
    Rerooting g1(n1);
    for (int i = 0; i < n1 - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g1.add_edge(a, b);
        g1.add_edge(b, a);
    }
    g1.build();
    int n2;
    cin >> n2;
    Rerooting g2(n2);
    for (int i = 0; i < n2 - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g2.add_edge(a, b);
        g2.add_edge(b, a);
    }
    g2.build();

    // x[k]: a_i = kとなるiの個数
    vector<ll> x(n1), y(n2);
    for (const auto &d : g1.ans) {
        ++x[d.dp];
    }
    for (const auto &d : g2.ans) {
        ++y[d.dp];
    }
    vector<ll> z = atcoder::convolution_ll(x, y);

    ll d1 = max_element(g1.ans.begin(), g1.ans.end(), [](Rerooting::DP a, Rerooting::DP b) { return a.dp < b.dp; })->dp;
    ll d2 = max_element(g2.ans.begin(), g2.ans.end(), [](Rerooting::DP a, Rerooting::DP b) { return a.dp < b.dp; })->dp;
    ll d = max(d1, d2);

    ll ans = 0;
    for (ll i = 0; i < (ll)z.size(); ++i) {
        ans += max(i + 1, d) * z[i];
    }

    cout << ans << endl;
    return 0;
}