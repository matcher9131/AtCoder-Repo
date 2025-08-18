#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, mw;
    cin >> n >> mw;
    vector<ll> w(n), v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }
    
    ll mv = 1e5;
    vector<vector<ll>> dp(n, vector<ll>(mv+1, INF));
    dp[0][0] = 0;
    dp[0][v[0]] = w[0];
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j <= mv; ++j) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if (j+v[i] <= mv) dp[i][j+v[i]] = min(dp[i][j+v[i]], dp[i-1][j] + w[i]);
        }
    }

    for (ll i = mv; i >= 0; --i) {
        if (dp[n-1][i] <= mw) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}