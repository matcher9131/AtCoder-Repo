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
    string s;
    cin >> s;

    // dp[i][j]: f(k, i)=jとなる(k,i)の個数
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = s[0] == '0';
    dp[0][1] = s[0] == '1';
    for (ll i = 1; i < n; ++i) {
        if (s[i] == '0') {
            dp[i][0] = 1;
            dp[i][1] = dp[i-1][0] + dp[i-1][1];
        } else {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0] + 1;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += dp[i][1];
    }
    cout << ans << endl;

    return 0;
}