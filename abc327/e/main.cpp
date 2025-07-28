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

    vector<double> coeff(n+1);
    for (ll i = 0; i < n; ++i) {
        coeff[i+1] = 0.9 * coeff[i] + 1.0;
    }

    // dp[i][j]: i回目まで見てj個を選んだときの第1項の分子の最大値
    vector<vector<double>> dp(n+1, vector<double>(n+1, -INF));
    for (ll i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (dp[i-1][j-1] > -INF) dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] * 0.9 + p[i-1]);
        }
    }

    double ans = -INF;
    for (ll j = 1; j <= n; ++j) {
        ans = max(ans, dp[n][j] / coeff[j] - 1200.0 / sqrt(j));
    }

    cout << setprecision(15) << ans << endl;

    return 0;
}