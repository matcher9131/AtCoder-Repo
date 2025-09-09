#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<double> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
        p[i] /= 100;
    }

    vector<vector<double>> dp(n+1, vector<double>(n+1));
    dp[0][0] = 1.0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j <= n; ++j) {
            dp[i][j] += dp[i-1][j] * (1 - p[i-1]);
            if (j < n) dp[i][j+1] += dp[i-1][j] * p[i-1];
        }
    }

    vector<double> sp(n+1);
    sp[n] = dp[n][n];
    for (ll i = n - 1; i >= 0; --i) {
        sp[i] = sp[i+1] + dp[n][i];
    }


    vector<double> dpe(x+1, -INF);
    dpe[0] = 0;
    function<double(ll)> dfs = [&](ll i) -> double {
        if (dpe[i] > -INF) return dpe[i];
        double numer = 1.0;
        for (ll k = 1; k <= n; ++k) {
            if (i-k < 0) break;
            numer += dp[n][k] * dfs(i-k);
        }
        double denom = 1 - dp[n][0];
        return dpe[i] = numer / denom;
    };

    cout << setprecision(15) << dfs(x) << endl;
    
    return 0;
}