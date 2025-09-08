#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

using S = ll;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}
using F = ll;
S mapping(F f, S x) {
    return f + x;
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}


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
    ll n;
    cin >> n;
    vector<tuple<ll, ll, ll>> edge(n-1);
    vector<vector<pair<ll, ll>>> g(n);
    LCA gl(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
        edge[i] = { a, b, w };
        gl.add_edge(a, b);
    }
    gl.build();

    vector<ll> dist(n);
    vector<ll> pre(n), post(n);
    function<void(ll,ll,ll,ll&)> dfs = [&](ll from, ll parent, ll d, ll &t) -> void {
        dist[from] = d;
        pre[from] = t++;
        for (const auto &[to, cost] : g[from]) {
            if (to == parent) continue;
            dfs(to, from, d + cost, t);
        }
        post[from] = t++;
    };
    ll time = 0;
    dfs(0, -1, 0, time);

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(2 * n);
    for (ll i = 0; i < n; ++i) {
        seg.set(pre[i], dist[i]);
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll i, w;
            cin >> i >> w;
            --i;
            auto [u, v, prevW] = edge[i];
            if (gl.get_lca(u, v) == v) swap(u, v);
            seg.apply(pre[v], post[v], w - prevW);
            get<2>(edge[i]) = w;
        } else {
            ll u, v;
            cin >> u >> v;
            --u;
            --v;
            ll ans = seg.get(pre[u]) + seg.get(pre[v]) - 2 * seg.get(pre[gl.get_lca(u, v)]);
            cout << ans << endl;
        }
    }

    return 0;
}