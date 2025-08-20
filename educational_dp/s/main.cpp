#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e16;

int main() {
    string s;
    ll d;
    cin >> s >> d;
    ll n = s.size();

    vector<vector<vector<mint>>> dp(n, vector<vector<mint>>(d, vector<mint>(2)));
    for (ll x = 0; x <= s[0] - '0'; ++x) {
        dp[0][x%d][x == s[0] - '0'] += 1;
    }
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j < d; ++j) {
            for (ll x = 0; x < s[i] - '0'; ++x) {
                dp[i][(j+x)%d][0] += dp[i-1][j][0] + dp[i-1][j][1];
            }
            dp[i][(j+(s[i] - '0'))%d][0] += dp[i-1][j][0];
            dp[i][(j+(s[i] - '0'))%d][1] += dp[i-1][j][1];
            for (ll x = s[i] - '0' + 1; x < 10; ++x) {
                dp[i][(j+x)%d][0] += dp[i-1][j][0];
            }
        }
    }

    cout << (dp[n-1][0][0] + dp[n-1][0][1] - 1).val() << endl;

    return 0;
}