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

struct Rerooting {
    struct DP {
        long long dp;
        DP(long long dp_) : dp(dp_) {}
    };
    const DP identity = DP(-1);
    function<DP(DP, DP)> merge = [](DP dp_cum, DP d) -> DP {
        return DP(max(dp_cum.dp, d.dp));
    };
    function<DP(DP)> add_root = [](DP d) -> DP {
        return DP(d.dp + 1);
    };
    struct Edge {
        int to;
    };
    
    using Graph = vector<vector<Edge>>;
    vector<vector<DP>> dp;
    vector<DP> ans;
    Graph G;
    Rerooting(int N) : G(N) {
        dp.resize(N);
        ans.assign(N, identity);
    }
    void add_edge(int a, int b) {
        G[a].push_back({b});
    }
    void build() {
        dfs(0);
        bfs(0, identity);
    }
    DP dfs(int v, int p = -1) {
        DP dp_cum = identity;
        int deg = G[v].size();
        dp[v] = vector<DP>(deg, identity);
        for (int i = 0; i < deg; i++) {
            int u = G[v][i].to;
            if (u == p) continue;
            dp[v][i] = dfs(u, v);
            dp_cum = merge(dp_cum, dp[v][i]);
        }
        return add_root(dp_cum);
    }
    void bfs(int v, const DP& dp_p, int p = -1) {
        int deg = G[v].size();
        for (int i = 0; i < deg; i++) {
            if (G[v][i].to == p) dp[v][i] = dp_p;
        }
        vector<DP> dp_l(deg + 1, identity), dp_r(deg + 1, identity);
        for (int i = 0; i < deg; i++) {
            dp_l[i + 1] = merge(dp_l[i], dp[v][i]);
        }
        for (int i = deg - 1; i >= 0; i--) {
            dp_r[i] = merge(dp_r[i + 1], dp[v][i]);
        }
        ans[v] = add_root(dp_l[deg]);
        for (int i = 0; i < deg; i++) {
            int u = G[v][i].to;
            if (u == p) continue;
            bfs(u, add_root(merge(dp_l[i], dp_r[i + 1])), v);
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

    ll ans = 0;
    for (int i = 0; i < n1; ++i) {
        ans += g1.ans[i].dp * (ll)n2;
    }
    for (int i = 0; i < n2; ++i) {
        ans += g2.ans[i].dp * (ll)n1;
    }
    ans += (ll)n1 * n2;

    cout << ans << endl;
    return 0;
}