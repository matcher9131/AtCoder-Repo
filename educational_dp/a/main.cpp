#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> dp(n, INF);
    dp[0] = 0;
    for (ll i = 0; i < n; ++i) {
        if (i+1 < n) dp[i+1] = min(dp[i+1], dp[i] + abs(a[i] - a[i+1]));
        if (i+2 < n) dp[i+2] = min(dp[i+2], dp[i] + abs(a[i] - a[i+2]));
    }

    cout << dp[n-1] << endl;

    return 0;
}