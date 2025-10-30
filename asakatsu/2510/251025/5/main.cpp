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

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(x+1, INF)));
    dp[0][0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll k = 0; k <= x; ++k) {
                if (dp[i][j][k] > y) continue;
                chmin(dp[i+1][j][k], dp[i][j][k]);
                if (k+a[i] <= x) chmin(dp[i+1][j+1][k+a[i]], dp[i][j][k] + b[i]);
            }
        }
    }

    ll ans = 0;
    for (ll j = 0; j <= n; ++j) {
        for (ll k = 0; k < x+1; ++k) {
            if (dp[n][j][k] <= y) {
                chmax(ans, j);
            }
        }
    }
    cout << (ans == n ? ans : ans + 1) << endl;

    return 0;
}