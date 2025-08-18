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

    vector<vector<ll>> dp(n, vector<ll>(mw+1));
    dp[0][w[0]] = v[0];
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j <= mw; ++j) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (j+w[i] <= mw) dp[i][j+w[i]] = max(dp[i][j+w[i]], dp[i-1][j] + v[i]);
        }
    }

    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;

    return 0;
}