#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

class Rerooting {
public:
    struct DP {
        pair<ll, ll> dp;
        DP(pair<ll, ll> dp_) : dp(dp_) {}
    };
    struct Edge {
        int to;
    };
    using Graph = vector<vector<Edge>>;

private:
    const DP id = DP({-1, -1});
    function<DP(DP, DP)> merge = [](DP acc, DP d) -> DP {
        return DP(max(acc.dp, d.dp));
    };
    function<DP(DP, int)> get_subtree_root = [](DP d, int v) -> DP {
        return d.dp.second == -1 ? DP({0, v}) : DP({d.dp.first+1, d.dp.second});
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
        // DP acc = id;
        DP acc = DP({-1, v});
        int deg = G[v].size();
        dp[v] = vector<DP>(deg, id);
        for (int i = 0; i < deg; i++) {
            int u = G[v][i].to;
            if (u == p) continue;
            dp[v][i] = dfs(u, v);
            acc = merge(acc, dp[v][i]);
        }
        return get_subtree_root(acc, v);
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
        ans[v] = get_subtree_root(dp_l[deg], v);
        for (int i = 0; i < deg; i++) {
            int u = G[v][i].to;
            if (u == p) continue;
            bfs(u, get_subtree_root(merge(dp_l[i], dp_r[i + 1]), v), v);
        }
    }
};

int main() {
    ll n;
    cin >> n;
    Rerooting g(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    g.build();

    for (ll i = 0; i < n; ++i) {
        cout << g.ans[i].dp.second+1 << endl;
    }

    return 0;
}