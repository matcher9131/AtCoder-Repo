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

    ll m = 10000;
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = 1;
    dp[0][a[0]] = 1;
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j <= m; ++j) {
            dp[i][j] |= dp[i-1][j];
            if (j+a[i] <= m) dp[i][j+a[i]] |= dp[i-1][j];
        }
    }

    cout << count(dp[n-1].begin(), dp[n-1].end(), true) << endl;


    return 0;
}