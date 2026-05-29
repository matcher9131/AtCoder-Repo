#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 1; i < n; ++i) {
        ll pi;
        cin >> pi;
        --pi;
        g[pi].push_back(i);
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<ll> d(n);
    for (ll i = 0; i < n; ++i) {
        cin >> d[i];
    }

    vector<ll> pre(n, -1), post(n), depth(n);
    auto dfs = [&](auto dfs, ll from, ll currentDepth, ll &t) -> void {
        pre[from] = t++;
        depth[from] = currentDepth;
        for (const ll to : g[from]) {
            if (pre[to] != -1) continue;
            dfs(dfs, to, currentDepth + 1, t);
        }
        post[from] = t++;
    };
    ll t = 0;
    dfs(dfs, 0, 0, t);

    atcoder::fenwick_tree<ll> fw(2*n);
    for (ll i = 0; i < n; ++i) {
        fw.add(pre[i], c[i]);
    }
    vector<ll> vertexes(n);
    iota(vertexes.begin(), vertexes.end(), 0);
    sort(vertexes.begin(), vertexes.end(), [&](ll a, ll b) { return depth[a] > depth[b]; });

    mint numer = 1, denom = 1;
    for (const ll v : vertexes) {
        ll partialSum = fw.sum(pre[v], post[v]);
        if (partialSum < d[v]) {
            cout << 0 << endl;
            return 0;
        }
        for (ll i = 0; i < d[v]; ++i) {
            numer *= partialSum - i;
            denom *= d[v] - i;
        }
        fw.add(pre[v], -d[v]);
    }

    cout << (numer / denom).val() << endl;

    return 0;
}