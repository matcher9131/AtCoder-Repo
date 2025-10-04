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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(301, vector<ll>(301, INF)));
    dp[0][0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= 300; ++j) {
            for (ll k = 0; k <= 300; ++k) {
                chmin(dp[i+1][j][k], dp[i][j][k]);
                chmin(dp[i+1][min(j+a[i], 300LL)][min(k+b[i], 300LL)], dp[i][j][k]+1);
            }
        }
    }

    ll ans = INF;
    for (ll j = x; j <= 300; ++j) {
        for (ll k = y; k <= 300; ++k) {
            chmin(ans, dp[n][j][k]);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}