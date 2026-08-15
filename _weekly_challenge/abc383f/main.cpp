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
    ll n, x, k;
    cin >> n >> x >> k;
    vector<vector<pair<ll, ll>>> items(n+1);
    for (ll i = 0; i < n; ++i) {
        ll p, u, c;
        cin >> p >> u >> c;
        items[c].emplace_back(p, u);
    }

    vector<vector<ll>> dp(n+1, vector<ll>(x+1, -INF));
    dp[0][0] = 0;
    for (ll ci = 1; ci <= n; ++ci) {
        for (const auto &[p, u] : items[ci]) {
            for (ll xi = x; xi >= p; --xi) {
                chmax(dp[ci][xi], dp[ci-1][xi-p] + u + k);
                chmax(dp[ci][xi], dp[ci][xi-p] + u);
            }
        }
        for (ll xi = 0; xi <= x; ++xi) {
            chmax(dp[ci][xi], dp[ci-1][xi]);
        }
    }

    cout << ranges::max(dp[n]) << endl;

    return 0;
}