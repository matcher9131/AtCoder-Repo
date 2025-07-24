#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

struct Edge {
    ll to;
};
using Graph = vector<vector<Edge>>;

class LCA {
private:
    Graph g;
    // parent[k][v]: vの2^k先の親
    vector<vector<int>> parent;
    vector<int> dist;

    void dfs(int from, int p, int d) {
        parent[0][from] = p;
        dist[from] = d;
        for (const auto& e : g[from]) {
            if (e.to == p) continue;
            dfs(e.to, from, d + 1);
        }
    }

public:
    LCA(int n): g(n) {
    }

    void add_edge(int a, int b) {
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    void build(int root = 0) {
        int n = g.size();
        int k = bit_width((unsigned)n);
        parent.assign(k, vector<int>(n, -1));
        dist.assign(n, -1);
        dfs(root, -1, 0);
        for (int ki = 0; ki + 1 < k; ++ki) {
            for (int v = 0; v < n; ++v) {
                if (parent[ki][v] < 0) {
                    parent[ki+1][v] = -1;
                } else {
                    parent[ki+1][v] = parent[ki][parent[ki][v]];
                }
            }
        }
    }

    int get_lca(int a, int b) {
        if (dist[a] < dist[b]) {
            swap(a, b);
        }
        int k = parent.size();
        // LCAまでの距離を揃える
        for (int ki = 0; ki < k; ++ki) {
            if ((dist[a] - dist[b]) & (1 << ki)) {
                a = parent[ki][a];
            }
        }
        // 二分探索でLCAを求める
        if (a == b) return a;
        for (int ki = k - 1; ki >= 0; --ki) {
            if (parent[ki][a] != parent[ki][b]) {
                a = parent[ki][a];
                b = parent[ki][b];
            }
        }
        return parent[0][a];
    }

    int get_dist(int a, int b) {
        return dist[a] + dist[b] - 2 * dist[get_lca(a, b)];
    }

    int get_depth(int a) {
        return dist[a];
    }
};


int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }
    LCA g(n);
    vector<pair<ll, ll>> edge(n-1);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g.add_edge(a, b);
        edge[i] = { a, b };
    }
    g.build();

    vector<ll> parent(n);
    for (ll i = 0; i < n-1; ++i) {
        auto [u, v] = edge[i];
        if (g.get_depth(u) < g.get_depth(v)) {
            parent[v] = u;
        } else {
            parent[u] = v;
        }
    }

    vector<ll> count(n);
    for (ll i = 0; i < m-1; ++i) {
        ll lca = g.get_lca(a[i], a[i+1]);
        ll v = a[i];
        while (v != lca) {
            ++count[v];
            v = parent[v];
        }
        v = a[i+1];
        while (v != lca) {
            ++count[v];
            v = parent[v];
        }
    }
    ll sumCount = accumulate(count.begin(), count.end(), 0LL);
    if ((sumCount + k) % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll r = (sumCount + k) / 2;
    if (r < 0 || r > sumCount) {
        cout << 0 << endl;
        return 0;
    }

    // dp[j]: 赤く塗られた辺の移動回数の和がiになるような塗り分け方
    vector<mint> dp(sumCount + 1);
    dp[0] = 1;
    // count[0]は辺が存在しない（rootから親へ向かう辺が存在しない）のでスキップ
    for (ll i = 1; i < n; ++i) {
        for (ll j = sumCount; j >= count[i]; --j) {
            dp[j] += dp[j - count[i]];
        }
    }

    cout << dp[r].val() << endl;

    return 0;
}