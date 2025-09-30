#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<mint>> dp(k+1, vector<mint>(n+1));
    dp[0][0] = 1;
    for (ll i = 0; i < k; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll x = 1; x <= m; ++x) {
                ll nj = j + x;
                if (nj > n) nj = 2*n - nj;
                dp[i+1][nj] += dp[i][j] / m;
            }
        }
    }

    mint ans = 0;
    for (ll i = 0; i <= k; ++i) {
        ans += dp[i][n];
    }
    cout << ans.val() << endl;

    return 0;
}