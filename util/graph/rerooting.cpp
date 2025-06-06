#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using ll = long long;

// 全方位木DP
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