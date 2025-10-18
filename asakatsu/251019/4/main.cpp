#include <bits/stdc++.h>
#include <atcoder/modint>
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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<ll>> g(n);
    for (ll i = 1; i < n; ++i) {
        ll v;
        cin >> v;
        --v;
        g[v].push_back(i);
    }

    vector<ll> depth(n, -1);
    auto dfs = [&](auto dfs, ll from, ll d) -> void {
        depth[from] = d;
        for (const ll to : g[from]) {
            if (depth[to] != -1) continue;
            dfs(dfs, to, d+1);
        }
    };
    dfs(dfs, 0, 0);
    
    vector<ll> depthSum(n);
    for (ll i = 0; i < n; ++i) {
        depthSum[depth[i]] += a[i];
    }

    for (ll i = n - 1; i >= 0; --i) {
        if (depthSum[i] > 0) {
            cout << "+" << endl;
            return 0;
        } else if (depthSum[i] < 0) {
            cout << "-" << endl;
            return 0;
        }
    }
    cout << "0" << endl;

    return 0;
}