#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[i][j][k]: i枚目まででj枚選んで合計がkになるような選び方の場合の数
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n+1, vector<ll>(50 * n + 1)));
    dp[0][0][0] = 1;
    dp[0][1][a[0]] = 1;
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j <= n; ++j) {
            for (ll k = 0; k <= 50*n; ++k) {
                dp[i][j][k] += dp[i-1][j][k];
                if (j >= 1 && k >= a[i]) dp[i][j][k] += dp[i-1][j-1][k-a[i]];
            }
        }
    }

    ll ans = 0;
    for (ll j = 1; j <= n; ++j) {
        for (ll k = 0; k <= 50*n; ++k) {
            if (k == m * j) ans += dp[n-1][j][k];
        }
    }
    cout << ans << endl;

    return 0;
}