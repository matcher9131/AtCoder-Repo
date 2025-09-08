#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m, l;
    cin >> n >> m >> l;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> table(l, vector<ll>(m));
    for (ll i = 0; i < l; ++i) {
        for (ll j = 0; j < m; ++j) {
            for (ll k = i; k < n; k += l) {
                table[i][j] += j >= a[k] ? j - a[k] : j+m - a[k];
            }
        }
    }

    vector<vector<ll>> dp(l, vector<ll>(m, INF));
    for (ll j = 0; j < m; ++j) {
        dp[0][j] = table[0][j];
    }
    for (ll i = 1; i < l; ++i) {
        for (ll j = 0; j < m; ++j) {
            for (ll k = 0; k < m; ++k) {
                dp[i][(j+k)%m] = min(dp[i][(j+k)%m], dp[i-1][j] + table[i][k]);
            }
        }
    }

    cout << dp[l-1][0] << endl;

    return 0;
}