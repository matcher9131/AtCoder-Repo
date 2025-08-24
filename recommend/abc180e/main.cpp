#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n), z(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }

    vector<vector<ll>> dp(1 << n, vector<ll>(n, INF));
    dp[1][0] = 0;
    for (ull bit = 1; bit < 1ULL << n; ++bit) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
            if (bit & (1ULL << j)) continue;
                ll newBit = bit | (1ULL << j);
                dp[newBit][j] = min(dp[newBit][j], dp[bit][i] + abs(x[j] - x[i]) + abs(y[j] - y[i]) + max(0LL, z[j] - z[i]));
            }
        }
    }

    ll ans = INF;
    for (ll i = 0; i < n; ++i) {
        ans = min(ans, dp[(1 << n) - 1][i] + abs(x[0] - x[i]) + abs(y[0] - y[i]) + max(0LL, z[0] - z[i]));
    }

    cout << ans << endl;
    return 0;
}