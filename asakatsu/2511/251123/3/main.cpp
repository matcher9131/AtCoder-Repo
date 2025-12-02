#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

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
};

int main() {
    ll n, nq;
    cin >> n >> nq;
    LCA g(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g.add_edge(a, b);
    }
    g.build();

    while (nq--) {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        cout << (g.get_dist(u, v) % 2 ? "Road" : "Town") << endl;
    }

    return 0;
}