#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(3));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    for (ll i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }

    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;

    return 0;
}