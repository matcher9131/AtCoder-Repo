#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<double> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<vector<double>> dp(n, vector<double>(n+1));
    dp[0][1] = p[0];
    dp[0][0] = 1-p[0];
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j <= n; ++j) {
            dp[i][j] += dp[i-1][j] * (1-p[i]);
            if (j+1 <= n) dp[i][j+1] += dp[i-1][j] * p[i];
        }
    }

    double ans = 0;
    for (ll j = (n+1)/2; j <= n; ++j) {
        ans += dp[n-1][j];
    }

    cout << setprecision(15) << ans << endl;

    return 0;
}