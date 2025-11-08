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
    vector<ll> w(n), h(n), b(n);
    ll sw = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> w[i] >> h[i] >> b[i];
        sw += w[i];
    }

    ll m = 500 * n;
    vector<vector<ll>> dp(n, vector<ll>(m+1, -1));
    dp[0][w[0]] = h[0];
    dp[0][0] = b[0];
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j <= m; ++j) {
            if (dp[i-1][j] == -1) continue;
            if (j+w[i] <= m) chmax(dp[i][j+w[i]], dp[i-1][j] + h[i]);
            chmax(dp[i][j], dp[i-1][j] + b[i]);
        }
    }

    ll ans = 0;
    for (ll j = 0; j <= sw/2; ++j) {
        chmax(ans, dp[n-1][j]);
    }
    cout << ans << endl;

    return 0;
}