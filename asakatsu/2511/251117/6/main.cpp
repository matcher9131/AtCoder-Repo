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
    ll x, y, n;
    cin >> x >> y >> n;
    vector<int> t(n), h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> t[i] >> h[i];
    }

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(x+1, vector<int>(x+y+1)));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= x; ++j) {
            for (ll k = 0; k <= x+y; ++k) {
                chmax(dp[i+1][j][k], dp[i][j][k]);
                if (j+1 <= x && k+t[i] <= x+y) chmax(dp[i+1][j+1][k+t[i]], dp[i][j][k] + h[i]);
            }
        }
    }

    int ans = 0;
    for (ll j = 0; j <= x; ++j) {
        for (ll k = 0; k <= x+y; ++k) {
            chmax(ans, dp[n][j][k]);
        }
    }
    cout << ans << endl;

    return 0;
}