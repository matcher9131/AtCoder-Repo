#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/scc>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }


int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    atcoder::scc_graph gscc(n);
    vector<pair<ll, ll>> edges(m);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        gscc.add_edge(a, b);
        edges[i] = {a, b};
    }

    auto groups = gscc.scc();
    ll numGroups = groups.size();
    vector<ll> giDic(n);
    for (ll gi = 0; gi < numGroups; ++gi) {
        for (const ll v : groups[gi]) {
            giDic[v] = gi;
        }
    }

    vector<unordered_set<ll>> g2(numGroups);
    for (const auto &[from, to] : edges) {
        g2[giDic[to]].insert(giDic[from]);
    }

    vector<bool> isBlack(numGroups);
    auto dfs2 = [&](auto dfs2, ll from) -> void {
        isBlack[from] = true;
        for (const ll to : g2[from]) {
            if (isBlack[to]) continue;
            dfs2(dfs2, to);
        }
    };

    ll nq;
    cin >> nq;
    while (nq--) {
        ll type, v;
        cin >> type >> v;
        --v;
        ll gi = giDic[v];
        if (type == 1) {
            if (!isBlack[gi]) dfs2(dfs2, gi);
        } else {
            cout << (isBlack[gi] ? "Yes" : "No") << "\n";
        }
    }
    

    return 0;
}