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
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n-1; ++i) {
        ll pi;
        cin >> pi;
        g[i+1].push_back(pi);
        g[pi].push_back(i+1);
    }

    vector<ll> size(n);
    vector<ll> ans(n);
    auto dfs = [&](auto f, ll from, ll parent) -> void {
        for (const ll to : g[from]) {
            if (to == parent) continue;
            f(f, to, from);
        }
        size[from] = 1;
        for (const ll to : g[from]) {
            if (to == parent) continue;
            size[from] += size[to];
            chmax(ans[from], size[to]);
        }
        chmax(ans[from], n - size[from]);
    };
    dfs(dfs, 0, -1);

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }

    // for (ll i = 0; i < (ll)size.size(); ++i) {
    //     cout << size[i] << " \n"[i == (ll)size.size() - 1];
    // }

    return 0;
}