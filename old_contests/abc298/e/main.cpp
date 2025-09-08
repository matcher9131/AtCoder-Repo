#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    --a;
    --b;

    // dp[i][j]: サイコロをi回振って地点jにいる確率
    vector<vector<mint>> dp0(n, vector<mint>(n)), dp1(n, vector<mint>(n));
    dp0[0][a] = 1;
    dp1[0][b] = 1;
    for (ll i = 0; i < n-1; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll pi = 1; pi <= p; ++pi) {
                dp0[i+1][min(j+pi, n-1)] += dp0[i][j] / p;
            }
            for (ll qi = 1; qi <= q; ++qi) {
                dp1[i+1][min(j+qi, n-1)] += dp1[i][j] / q;
            }
        }
    }

    mint ans = 0;
    for (ll i = 1; i < n; ++i) {
        ans += (1 - dp1[i-1][n-1]) * (dp0[i][n-1] - dp0[i-1][n-1]);
    }

    cout << ans.val() << endl;
    
    return 0;
}