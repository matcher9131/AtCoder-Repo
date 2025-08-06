#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    mint ans = 0;
    for (ll c = 1; c <= n; ++c) {
        // dp[i][j][k]: i番目まで見てj個選んで(和 mod C)がkになるような選び方
        vector<vector<vector<mint>>> dp(n, vector<vector<mint>>(c+1, vector<mint>(c)));
        dp[0][0][0] = 1;
        dp[0][1][a[0] % c] = 1;
        for (ll i = 1; i < n; ++i) {
            for (ll j = 0; j <= c; ++j) {
                for (ll k = 0; k < c; ++k) {
                    dp[i][j][k] = dp[i-1][j][k];
                    if (j > 0) dp[i][j][k] += dp[i-1][j-1][(k - a[i]%c + c) % c];
                }
            }
        }
        ans += dp[n-1][c][0];
    }

    cout << ans.val() << endl;
    return 0;
}