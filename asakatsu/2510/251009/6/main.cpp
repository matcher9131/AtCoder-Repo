#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<ll> t(m);
    for (ll j = 0; j < m; ++j) {
        cin >> t[j];
    }

    vector<vector<mint>> dp(n+1, vector<mint>(m+1));
    dp[0][0] = 1;
    for (ll i = 0; i <= n; ++i) {
        for (ll j = 0; j <= m; ++j) {
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
            if (i > 0 && j > 0 && s[i-1] != t[j-1]) dp[i][j] -= dp[i-1][j-1];
        }
    }

    cout << dp[n][m].val() << endl;

    return 0;
}