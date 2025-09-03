#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;

    // dp[i][j]: 人iまでで人iが人0と(j=0: 異なる数, j=1: 等しい数）になるような渡し方
    vector<vector<mint>> dp(n, vector<mint>(2));
    dp[0][0] = 0;
    dp[0][1] = m;
    for (ll i = 1; i < n; ++i) {
        dp[i][0] = (m-2) * dp[i-1][0] + (m-1) * dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[n-1][0].val() << endl;

    return 0;
}