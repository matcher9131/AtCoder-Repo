#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, w, c;
    cin >> n >> w >> c;
    // w, v
    vector<vector<pair<ll, ll>>> item(50);
    for (ll i = 0; i < n; ++i) {
        ll wi, vi, ci;
        cin >> wi >> vi >> ci;
        --ci;
        item[ci].emplace_back(wi, vi);
    }

    vector<vector<ll>> dp(c+1, vector<ll>(w+1));
    for (ll ci = 0; ci < 50; ++ci) {
        if (item[ci].empty()) continue;

        vector<vector<ll>> dp2(c+1, vector<ll>(w+1));
        for (const auto &[wi, vi] : item[ci]) {
            for (ll cj = 1; cj <= c; ++cj) {
                for (ll k = w; k >= wi; --k) {
                    dp2[cj][k] = max({dp2[cj][k], dp2[cj][k-wi] + vi, dp[cj-1][k-wi] + vi});
                }
            }
        }

        for (ll cj = 0; cj <= c; ++cj) {
            for (ll k = 0; k <= w; ++k) {
                dp[cj][k] = max(dp[cj][k], dp2[cj][k]);
            }
        }
    }
    
    cout << dp[c][w] << endl;

    return 0;
}