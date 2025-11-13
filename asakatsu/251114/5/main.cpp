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
    ll w, n, c;
    cin >> w >> n >> c;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(c+1, vector<ll>(w+1)));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= c; ++j) {
            for (ll k = 0; k <= w; ++k) {
                chmax(dp[i+1][j][k], dp[i][j][k]);
                if (j+1 <= c && k+a[i] <= w) chmax(dp[i+1][j+1][k+a[i]], dp[i][j][k] + b[i]);
            }
        }
    }

    ll ans = 0;
    for (ll j = 0; j <= c; ++j) {
        for (ll k = 0; k <= w; ++k) {
            chmax(ans, dp[n][j][k]);
        }
    }
    cout << ans << endl;

    return 0;
}