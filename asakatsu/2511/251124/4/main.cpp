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
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(h+1, INF));
    dp[0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= h; ++j) {
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][min(h, j + a[i])], dp[i+1][j] + b[i]);
        }
    }

    cout << dp[n][h] << endl;

    return 0;
}