#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> pow(n, vector<ll>(5));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 5; ++j) {
            cin >> pow[i][j];
        }
    }

    vector<int> pattern(n);
    auto isOK = [&](ll x) -> bool {
        for (ll i = 0; i < n; ++i) {
            int bit = 0;
            for (ll j = 0; j < 5; ++j) {
                if (pow[i][j] >= x) bit |= 1 << j;
            }
            pattern[i] = bit;
        }

        // dp[i][j][k]: i人目まで見てj人を選んでパターンがkになるかどうか
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(4, vector<bool>(32)));
        dp[0][0][0] = true;
        dp[0][1][pattern[0]] = true;
        for (ll i = 1; i < n; ++i) {
            for (ll j = 0; j < 4; ++j) {
                for (ll k = 0; k < 32; ++k) {
                    dp[i][j][k] = dp[i][j][k] || dp[i-1][j][k];
                    if (j < 3) dp[i][j+1][k | pattern[i]] = dp[i][j+1][k | pattern[i]] || dp[i-1][j][k];
                }
            }
        }

        return dp[n-1][1][31] || dp[n-1][2][31] || dp[n-1][3][31];
    };

    ll ng = 1e9 + 1;
    ll ok = 0;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    return 0;
}