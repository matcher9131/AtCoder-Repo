#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> dp(n, INF);
    dp[0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 1; j <= k; ++j) {
            if (i+j < n) dp[i+j] = min(dp[i+j], dp[i] + abs(a[i] - a[i+j]));
        }
    }

    cout << dp[n-1] << endl;

    return 0;
}