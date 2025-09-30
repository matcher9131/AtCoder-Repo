#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n), z(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }
    ll restZ = (accumulate(z.begin(), z.end(), 0LL) + 1) / 2;
    for (ll i = 0; i < n; ++i) {
        if (x[i] > y[i]) restZ -= z[i];
    }
    if (restZ <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> need(n);
    for (ll i = 0; i < n; ++i) {
        if (x[i] > y[i]) need[i] = 0;
        else need[i] = (x[i] + y[i] + 1) / 2 - x[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(restZ + 1, INF));
    dp[0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        if (x[i] > y[i]) {
            dp[i+1] = dp[i];
        } else {
            for (ll j = 0; j <= restZ; ++j) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                dp[i+1][min(j+z[i], restZ)] = min(dp[i+1][min(j+z[i], restZ)], dp[i][j] + need[i]);
            }
        }
    }

    cout << dp[n][restZ] << endl;

    return 0;
}