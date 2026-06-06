#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/math>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> u(m), v(m);
    for (ll i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
        --u[i];
        --v[i];
    }
    
    ll nw;
    cin >> nw;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    vector<vector<ll>> g(n*nw);
    for (ll i = 0; i < m; ++i) {
        for (ll j = 0; j < nw; ++j) {
            ll nj = (j+1) % nw;
            if (s[u[i]][j] == 'o' && s[v[i]][nj] == 'o') {
                g[u[i] + j*n].push_back(v[i] + nj*n);
            }
            if (s[v[i]][j] == 'o' && s[u[i]][nj] == 'o') {
                g[v[i] + j*n].push_back(u[i] + nj*n);
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < nw; ++j) {
            ll nj = (j+1) % nw;
            if (s[i][j] == 'o' && s[i][nj] == 'o') {
                g[i + j*n].push_back(i + nj*n);
            }
        }
    }
    for (ll i = 0; i < n*nw; ++i) {
        sort(g[i].begin(), g[i].end());
    }

    vector<bool> pre(n*nw), post(n*nw);
    auto dfs = [&](auto dfs, ll from) {
        pre[from] = true;
        for (const ll to : g[from]) {
            if (post[to]) continue;
            if (pre[to]) return true;
            bool result = dfs(dfs, to);
            if (result) return true;
        }
        post[from] = true;
        return false;
    };

    for (ll i = 0; i < n*nw; ++i) {
        if (pre[i]) continue;
        bool result = dfs(dfs, i);
        if (result) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}