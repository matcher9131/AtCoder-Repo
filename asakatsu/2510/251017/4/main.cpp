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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
    }

    ll ans = -INF;
    vector<ll> dp(n, INF);
    for (ll i = 0; i < n; ++i) {
        if (dp[i] != INF) chmax(ans, a[i] - dp[i]);
        for (const ll to : g[i]) {
            chmin(dp[to], dp[i]);
            chmin(dp[to], a[i]);
        }
    }
    cout << ans << endl;

    return 0;
}