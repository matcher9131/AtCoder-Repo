#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<ll> dp(1 << n, -INF);
    for (ull bit = 0; bit < 1ULL << n; ++bit) {
        ll sum = 0;
        for (ll i = 0; i < n; ++i) {
            for (ll j = i+1; j < n; ++j) {
                if ((bit & (1 << i)) && (bit & (1 << j))) sum += a[i][j];
            }
        }
        dp[bit] = sum;
        ull subBit = bit;
        while (true) {
            dp[bit] = max(dp[bit], dp[subBit] + dp[bit & (~subBit)]);
            if (subBit == 0) break;
            subBit = (subBit - 1) & bit;
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}