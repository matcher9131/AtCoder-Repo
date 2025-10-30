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
    vector<double> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<double>> dp(n+1, vector<double>(n+1, -INF));
    dp[0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= n; ++j) {
            if (dp[i][j] == -INF) continue;
            chmax(dp[i+1][j], dp[i][j]);
            if (j < n) chmax(dp[i+1][j+1], 0.9 * dp[i][j] + a[i]);
        }
    }

    double ans = -INF;
    for (ll j = 0; j <= n; ++j) {
        chmax(ans, dp[n][j] / ((1.0 - pow(0.9, j)) / 0.1) - 1200.0 / sqrt(j));
    }
    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}