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

    vector<mint> dp(1 << n);
    dp[0] = 1;
    for (ull bit = 0; bit < 1ULL << n; ++bit) {
        ll i = popcount(bit);
        for (ll j = 0; j < n; ++j) {
            if (bit & (1 << j)) continue;
            if (!a[i][j]) continue;
            dp[bit | (1 << j)] += dp[bit];
        }
    }

    cout << dp[(1 << n) - 1].val() << endl;

    return 0;
}