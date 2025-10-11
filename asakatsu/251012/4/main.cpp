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
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(2));
    dp[0][0] = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 2; ++j) {
            dp[i+1][j] += dp[i][j];
            dp[i+1][(j+a[i])%2] += dp[i][j];
        }
    }

    cout << dp[n][p] << endl;

    return 0;
}